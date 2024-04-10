#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,inf=1e9;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct seg{
	int l,r;
	bool operator <(seg i)const{return (l==i.l)?(r>i.r):(l<i.l);}
}s[maxn],t[maxn];
int tp,st[maxn];
bool ban[maxn];
ll f[maxn][2];
int main(){
//    freopen("CF1566F.in","r",stdin);
//    freopen("CF1566F.out","w",stdout);
    int T;
	T=read();
	while(T--){
		int n,m;
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1;i<=m;i++){
			int l,r;
			l=read();r=read();
			s[i]=(seg){l,r};ban[i]=0;
		}
		sort(s+1,s+m+1);
		tp=0;
		for(int i=1;i<=m;i++){
			while(tp&&s[i].r<=s[st[tp]].r)ban[st[tp--]]=1;
			st[++tp]=i;
		}
		int pos=1;
		for(int i=1;i<=m;i++){
			if(ban[i])continue;
			while(pos<n&&a[pos]<s[i].l)pos++;
			if(a[pos]>=s[i].l&&a[pos]<=s[i].r)ban[i]=1;
		}
		int len=0;
		for(int i=1;i<=m;i++)if(!ban[i])t[++len]=s[i];
		a[0]=-inf-1;
		for(int i=1;i<=n;i++)f[i][0]=f[i][1]=1e18;
		for(int i=1;i<=n;i++){
			int l=lower_bound(t+1,t+len+1,(seg){a[i-1],inf})-t;
			int r=lower_bound(t+1,t+len+1,(seg){a[i],inf})-t-1;
			if(i==1){
				if(l<=r)f[i][0]=2ll*(a[i]-t[l].r),f[i][1]=a[i]-t[l].r;
				else f[i][0]=f[i][1]=0;
				continue;
			}
			for(int j=l-1;j<=r;j++){
				ll v1=((j>=l)?(t[j].l-a[i-1]):0),v2=((j<r)?(a[i]-t[j+1].r):0);
				f[i][0]=min(f[i][0],f[i-1][0]+v1+v2*2);
				f[i][0]=min(f[i][0],f[i-1][1]+v1*2+v2*2);
				f[i][1]=min(f[i][1],f[i-1][0]+v1+v2);
				f[i][1]=min(f[i][1],f[i-1][1]+v1*2+v2);
			}
		}
		if(len&&t[len].l>a[n])f[n][0]=f[n][0]+(t[len].l-a[n]),f[n][1]=f[n][1]+2ll*(t[len].l-a[n]);
		printf("%lld\n",min(f[n][0],f[n][1]));
	}
    return 0;
}