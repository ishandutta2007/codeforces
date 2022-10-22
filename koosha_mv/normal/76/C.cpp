#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=(1<<22),M=22;

int n,k,t,m,ans,a[M][M],dp[N],b[M],mark[M];
vector<pair<int,int> > v;
string s;

int main(){
	cin>>n>>k>>t;
	cin>>s;
	f(i,0,k){
		cin>>b[i];
	}
	f(i,0,k)
		f(j,0,k)
			cin>>a[i][j];
	f_(i,n-1,0){
		int mask=(1<<k)-1;
		mark[s[i]-'A']=1;
		f(j,0,v.size()){
			int x=a[s[i]-'A'][v[j].S];
			dp[mask]+=x;
			if(s[i]-'A'==v[j].S){
				dp[mask^(1<<v[j].S)]-=x;
			}
			else{
				dp[mask^(1<<v[j].S)]-=x;
				dp[mask^(1<<(s[i]-'A'))]-=x;
				dp[mask^(1<<v[j].S)^(1<<(s[i]-'A'))]+=x;
			}
			mask^=(1<<v[j].S);
			if(v[j].S==s[i]-'A')
				break;
		}	
		vector<pair<int,int> > V;
		V.pb(mp(i,s[i]-'A'));
		f(j,0,v.size())
			if(v[j].S!=s[i]-'A')
				V.pb(v[j]);
		v=V;
	}
	f(i,0,k)
		if(!mark[i])
			m|=(1<<i);
	f(i,0,k)
		f_(mask,(1<<k)-1,0)
			if(mask&(1<<i))
				dp[mask^(1<<i)]+=dp[mask];
	f(i,0,k)
		f(mask,0,(1<<k))
			if((mask&(1<<i))==0)
				dp[mask]+=b[i];
	//cout<<m<<endl;
	f(mask,1,(1<<k)){
		if ((m|mask)==mask && mask!=m) {
			ans+=(dp[mask]<=t);
		}
	}
	cout<<ans;
}