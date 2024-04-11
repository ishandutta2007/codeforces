#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define Add(x,y) x=(x+y)%mod
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5002,mod=1e9+7;

int n,m,ans,RG[N],G[N],C[N][N];
string s[N];
map<string,int> mark;

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

int main(){
	G[0]=RG[0]=ans=1;
	f(i,0,N){
		C[0][i]=1;
		f(j,1,i+1)
			C[j][i]=(C[j][i-1]+C[j-1][i-1])%mod;
	}
	f(i,1,N){
		f(j,0,i){
			Add(G[i],1ll*C[j][i-1]*G[i-j-1]%mod);
		}
		RG[i]=pow(G[i],mod-2,mod);
	}
	cin>>m>>n;
	f(i,0,n)
		cin>>s[i];
	f(j,0,m){
		string t;
		f(i,0,n)
			t+=s[i][j];
		ans=1ll*ans*RG[mark[t]]%mod;
	//	eror(ans);
		mark[t]++;
		ans=1ll*ans*G[mark[t]]%mod;
	}
	cout<<ans;
}