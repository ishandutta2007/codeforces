#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define min(a,b)(a<b?a:b)
#define max(a,b)(a>b?a:b)
#define _(x)(x+fh>>1)
using namespace std;
const int N=1e5+5;
int n,x,y,mi[N],ma[N];
struct no{int x,y;}a[N];
bool cmp(no x,no y){return x.x<y.x;}
ll cnt(int fh){
	ll t=0;
	mi[n+1]=1e9;ma[n+1]=-1e9;
	fd(i,1,n){
		mi[i]=mi[i+1];ma[i]=ma[i+1];
		if((a[i].x+fh)&1)mi[i]=min(mi[i],a[i].y),ma[i]=max(ma[i],a[i].y);
	}
	int l1=1e9,r1=-1e9,l2,r2;
	int j=1;
	fo(i,_(a[1].x),_(a[n].x)){
		for(;j<=n&&(!((a[j].x+fh)&1)||_(a[j].x)==i);j++){
			if(!((a[j].x+fh)&1))continue;
			l1=min(l1,a[j].y);r1=max(r1,a[j].y);
		}
		l2=mi[j];r2=ma[j];
		if(l1<=r2&&l2<=r1)t+=min(r1,r2)-max(l1,l2)>>1;
	}
	return t;
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)scanf("%d%d",&x,&y),a[i].x=x+y,a[i].y=x-y;
	sort(a+1,a+n+1,cmp);
	printf("%I64d",cnt(1)+cnt(0));
}