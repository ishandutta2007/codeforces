#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long 
using std::min;
using std::max;

long long x[4],y[4],ans,modx[4],mody[4],ansx[4],ansy[4];
int num[4];
int T;
long long abs(long long x){
	return x<0?-x:x;
}
void check(long long d,long long _x,long long _y){
	if(!d)return;
	for(int i=0;i<4;i++)num[i]=i;
	modx[0]=_x,mody[0]=_y;
	modx[1]=_x+d,mody[1]=_y;
	modx[2]=_x,mody[2]=_y+d;
	modx[3]=_x+d,mody[3]=_y+d;
	do{
		bool cando=1;
		long long tem=0;
		for(int i=0;i<4;i++){
			if(x[i]!=modx[num[i]]&&y[i]!=mody[num[i]]){
				cando=0;
				break;
			}
			else tem=max(tem,abs(x[i]-modx[num[i]])+abs(y[i]-mody[num[i]]));
		}
		if(cando&&ans>tem){
			ans=tem;
			for(int i=0;i<4;i++)ansx[i]=modx[num[i]],ansy[i]=mody[num[i]];
		}
	}while(std::next_permutation(num,num+4));
}
signed main(){
//	freopen("CF666D.in","r",stdin);
//	freopen("CF666D.out","w",stdout);
	scanf("%I64d",&T);
	for(int fd=1;fd<=T;fd++){
		for(int i=0;i<4;i++)scanf("%I64d%I64d",x+i,y+i);
		ans=1000000000000000000ll;
		for(int i=0;i<4;i++)
			for(int j=i+1;j<4;j++)
				for(int k=0;k<4;k++)
					for(int l=0;l<4;l++){
						long long d=abs(x[j]-x[i]);
						check(d,x[k],y[l]);
						check(d,x[k]-d,y[l]);
						check(d,x[k],y[l]-d);
						check(d,x[k]-d,y[l]-d);
						d=abs(y[j]-y[i]);
						check(d,x[k],y[l]);
						check(d,x[k]-d,y[l]);
						check(d,x[k],y[l]-d);
						check(d,x[k]-d,y[l]-d);
					}
		for(int i=1;i<4;i++){
			if(x[i]==x[0]){
				int _mn=1000000000,_mx=-1000000000;
				for(int j=0;j<4;j++)_mn=min(_mn,x[j]),_mx=max(_mx,x[j]);
				for(int k=0;k<4;k++)
					for(int l=k+1;l<4;l++){
						check(_mx-_mn,_mn,(y[k]+y[l]-_mx+_mn)>>1);
						check(_mx-_mn,_mn,(y[k]+y[l])>>1);
						check(_mx-_mn,_mn,((y[k]+y[l])>>1)-_mx+_mn);
						check(_mx-_mn,_mn,(y[k]+y[l]+_mx+_mn)>>1);
					}
			}
			if(y[i]==y[0]){
				int _mn=1000000000,_mx=-1000000000;
				for(int j=0;j<4;j++)_mn=min(_mn,y[j]),_mx=max(_mx,y[j]);
				for(int k=0;k<4;k++)
					for(int l=k+1;l<4;l++){
						check(_mx-_mn,(x[k]+x[l]-_mx+_mn)>>1,_mn);
						check(_mx-_mn,(x[k]+x[l])>>1,_mn);
						check(_mx-_mn,((x[k]+x[l])>>1)-_mx+_mn,_mn);
						check(_mx-_mn,(x[k]+x[l]+_mx+_mn)>>1,_mn);
					}
			}
		}
		if(ans==1000000000000000000ll)puts("-1");
		else{
			printf("%I64d\n",ans);
			for(int i=0;i<4;i++)printf("%I64d %I64d\n",ansx[i],ansy[i]);
		}
	}
}