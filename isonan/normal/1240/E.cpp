#include <cstdio>
#include <algorithm>

int n,a[500001],last[500001];
long long f[500001],fin,cnt;
struct big{
	int mx,skdmx;
	void init(){mx=skdmx=-1;}
	void upd(const int &n){(mx<n)?(skdmx=mx,mx=n):(skdmx=std::max(skdmx,n));}
}val[500010];
big getval(int i,int y){
	big ans=val[i/y+1];
	int r=std::min(500000,(i/y)*y+y-1),lst=last[r],skdlst=(a[lst]-a[lst-1]>1)?lst:last[lst-1];
	lst=(lst<i)?-1:(lst%y);
	skdlst=(skdlst<i)?-1:(skdlst%y);
	ans.upd(lst);
	ans.upd(skdlst);
	return ans;
}
bool check(int x,int y){
	if((x<<1)<=500000){
		big now=getval(x<<1,y);
		long long N=(500000ll*y+now.mx-(x<<1))/y;
		if(~now.mx&&cnt-(500000-N)>=x)return 1;
	}
	big now=getval(x,y);
	long long N=(500000ll*y+now.mx-x)/y+(500000ll*y+now.skdmx-x)/y;
	if(~now.mx&&~now.skdmx&&cnt-(1000000-N)>=x)return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1,tem;i<=n;i++)scanf("%d",&tem),++a[tem];
	for(int i=1;i<=500000;i++)last[i]=(a[i]?i:last[i-1]),a[i]+=a[i-1];
	for(int y=2;y<=500000;y++){
		cnt=0;
		big now,tem;
		now.init();
		tem.init();
		for(int i=0;i<=500000;i+=y)
			cnt+=1ll*(a[std::min(500000,i+y-1)]-(i?a[i-1]:0))*(i/y);
		val[500000/y+1].init();
		for(int i=500000/y;~i;--i){
			int l=i*y,r=std::min(i*y+y-1,500000);
			int lst=last[r],skdlst=lst?((a[lst]-a[lst-1]>1)?lst:last[lst-1]):0;
			lst=(lst<l)?-1:lst%y;
			skdlst=(skdlst<l)?-1:skdlst%y;
			val[i]=val[i+1];
			val[i].upd(lst);
			val[i].upd(skdlst);
		}
		int l=2,r=500000,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,y))ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(ans!=-1)fin=std::max(fin,1ll*ans*y);
	}
	printf("%I64d\n",fin);
}