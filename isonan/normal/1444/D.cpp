#include <cstdio>
#include <bitset>
#include <algorithm>

int t,h,v,x[1010],l[1010],y[1010];
int ax[1010],ay[1010];
std::bitset<1000001>f[501];
bool solve(int *l,int *x,int h){
	if(h>500)return 0;
	int sum=0;
	for(int i=1;i<=h;i++)sum+=l[i];
	if(sum&1)return 0;
	f[0].set(0);
	std::sort(l+1,l+h+1);
	for(int i=1;i<=h;i++)
		f[i]=f[i-1]|(f[i-1]<<l[i]);
	sum>>=1;
	if(!f[h][sum])return 0;
	x[1]=x[h+1]=0;
	int L=1,r=h+1;
	for(int i=h;i;i--){
		if(sum>=l[i]&&f[i-1][sum-l[i]]){
			++L;
			x[L]=x[L-1]+l[i];
			sum-=l[i];
		}
		else{
			--r;
			x[r]=x[r+1]+l[i];
		}
	}
	return 1;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		bool ans=1;
		scanf("%d",&h);
		for(int i=1;i<=h;i++)scanf("%d",l+i);
		ans&=solve(l,x,h);
		scanf("%d",&v);
		for(int i=1;i<=v;i++)scanf("%d",l+i);
		ans&=(h==v);
		ans&=solve(l,y,v);
		if(!ans){
			puts("No");
			continue;
		}
		std::reverse(y+2,y+v+1);
		for(int i=1;i<=h;i++)
			ax[(i<<1)-2]=ax[(i<<1)-1]=x[i];
		ax[h<<1]=0;
		for(int i=1;i<=v;i++)
			ay[(i<<1)-1]=ay[i<<1]=y[i];
		ax[(h<<1)+1]=ay[(h<<1)+1]=0;
		for(int i=1;i<=h+v;i+=2)
			for(int j=i+1;j<=h+v;j+=2){
				bool bad=1;
				int l=ax[i],r=ax[i+1];
				if(l>r)std::swap(l,r);
				bad&=(l<=ax[j]&&r>=ax[j]);
				l=ay[j],r=ay[j+1];
				if(l>r)std::swap(l,r);
				bad&=(l<=ay[i]&&r>=ay[i]);
				bad&=(ax[i]!=ax[j]||ay[i]!=ay[j]);
				bad&=(ax[i+1]!=ax[j]||ay[i+1]!=ay[j]);
				bad&=(ax[i]!=ax[j+1]||ay[i]!=ay[j+1]);
				bad&=(ax[i+1]!=ax[j+1]||ay[i+1]!=ay[j+1]);
				ans&=(bad==0);
			}
		if(!ans){
			puts("No");
		}
		else{
			puts("Yes");
			for(int i=1;i<=h+v;i++)printf("%d %d\n",ax[i],ay[i]);
		}
	}
}