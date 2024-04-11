#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2222,mod=1e9+7;

int n,t,ans,a[N],cnt1[2][N],cntq[2][N];
string s[2];

int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k<0 || k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int calc(int a0,int b0,int a1,int b1){
	return C(a1-a0+b1,b0+b1);
}
void Main(){
	ans=0;
	cin>>n;
	cin>>s[0]>>s[1];
	s[0]=' '+s[0];
	s[1]=' '+s[1];
	f(k,0,2){
		f(i,1,n+1){
			if(i&1){
				if(s[k][i]=='1') s[k][i]='0';
				else if(s[k][i]=='0') s[k][i]='1';
			}
			cnt1[k][i]=cnt1[k][i-1]+(s[k][i]=='1');
			cntq[k][i]=cntq[k][i-1]+(s[k][i]=='?');
		}
	}
	f(i,1,n+1){
		f(j,1,n+1){
			Add(ans,1ll*calc(cnt1[0][i-1],cntq[0][i-1],cnt1[1][j-1],cntq[1][j-1])*calc(cnt1[0][n]-cnt1[0][i],cntq[0][n]-cntq[0][i],cnt1[1][n]-cnt1[1][j],cntq[1][n]-cntq[1][j])*(s[0][i]!='0')*(s[1][j]!='0')%mod*abs(i-j)%mod);
		}
	}
	cout<<ans<<'\n';
}

int main(){
	make_fac();
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
3
???
???
*/