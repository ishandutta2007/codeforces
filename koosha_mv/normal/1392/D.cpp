#include <bits/stdc++.h>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,dp[N];
string s,m;

int main(){
	cin>>t;
	while(t--){
		int ans=0,b=0;
		cin>>n>>s;
		fill(dp,dp+n+2,0);
		f(i,1,n) if(s[i]!=s[i-1]) b=i;
		if(!b){
			cout<<(n+2)/3<<'\n';
		}
		else{
			m="";
			f(i,0,n)
				m+=s[(b+i)%n];
			int last=0;
			f(i,0,n){
				if(i==0 || m[i]!=m[i-1]) last=1;
				else last++;
				if(i==n-1 || m[i]!=m[i+1]) ans+=last/3;
			}
			cout<<ans<<'\n';
		}
	}
}