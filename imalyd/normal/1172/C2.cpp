//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define I inline
//#define R register int
namespace io{
    const int l=1<<19;
    char buf[l],*s,*t,c;
    char gc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,l,stdin);
            return s==t?EOF:*s++;
        }
        return *s++;
    }
    template<class IT>void gi(IT &x){
        x=0;c=gc();while(c<'0'||c>'9')c=gc();
        while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
    }
};
using io::gi;
template<class IT>void chkmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>void chkmax(IT &a,IT b){if(a<b)a=b;}

const int N=200005,M=3005;
const ll p=998244353ll,p2=998244351ll;
int n,m;
ll e1,e0,s,s0,s1,sn,s2;
int a[N];
ll w[N],inv[M<<1],dp[M][M];
ll expo(ll a,ll b){
	static ll c;c=1ll;
	while(b!=0ll){
		if((b&1ll)==1ll)c=c*a%p;
		b>>=1;a=a*a%p;
	}
	return c;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%I64d",&w[i]);
	for(int i=1;i<=n;i++){if(a[i]==1)s1+=w[i];else s0+=w[i];}
	s=s0+s1;sn=s0;s2=s0+s1;
	dp[0][0]=1ll;
	for(int i=0;i<=m<<1;i++)inv[i]=expo(s2+i-m,p2);
	for(int i=0;i< m;i++){
		for(int j=0;j<=i;j++)if(dp[i][j]!=0ll){
			dp[i+1][j+1]=(dp[i+1][j+1]+ dp[i][j]*((s1+j)*inv[m-i+(j<<1)]%p) )%p;
			dp[i+1][j  ]=(dp[i+1][j  ]+ dp[i][j]*((sn+j)*inv[m-i+(j<<1)]%p) )%p;
		}
		--sn;
	}
	for(int i=1;i<=m;i++)e1=(e1+dp[m][i]*i)%p;
	e0=(m-e1+p)%p;
	for(int i=1;i<=n;i++){
		if(a[i]==1)printf("%I64d\n",(w[i]+(w[i]*expo(s1,p2)%p)*e1    )%p);
		else       printf("%I64d\n",(w[i]-(w[i]*expo(s0,p2)%p)*e0%p+p)%p);
	}
	return 0;
}