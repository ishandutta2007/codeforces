#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int maxn=50005;
ll a[maxn],s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int tp,st[maxn];
int l[maxn],f[maxn];
ll mx[maxn][21];
ll query(int l,int r){
	if(l>r)swap(l,r);
	int len=__lg(r-l+1);
	return max(mx[l][len],mx[r-(1<<len)+1][len]);
}
signed main(){
	int T;
	T=read();
	while(T--){
		int n,x;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		x=read();
		for(int i=1;i<=n;i++)a[i]-=x,s[i]=s[i-1]+a[i];
		for(int i=0;i<=n;i++)mx[i][0]=s[i];
		for(int p=1;p<=20;p++)
			for(int i=0;i+(1<<p)-1<=n;++i)
				mx[i][p]=max(mx[i][p-1],mx[i+(1<<(p-1))][p-1]);
		for(int i=1,L,R,mid;i<=n;++i){
			L=0,R=i-2;
			if(L>R){l[i]=-1;continue;}
			while(L<R){
				mid=(L+R+1)>>1;
				if(query(mid,i-2)>s[i])L=mid;
				else R=mid-1;
			}
			if(query(L,i-2)<=s[i])l[i]=-1;
			else l[i]=L+1;
		}
		tp=0;
		for(int i=n;i>=1;i--){
			if(l[i]==-1)continue;
			while(tp&&l[st[tp]]<l[i])tp--;
			st[++tp]=i;
		}
		reverse(st+1,st+tp+1);
		int pos=0;
		for(int i=1;i<=tp;i++){
			while(pos+1<i&&st[pos+1]<l[st[i]])++pos;
			f[i]=f[pos]+1;
		}
		int res=f[tp];
		printf("%lld\n",n-res);
	}
    return 0;
}