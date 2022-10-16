#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
vector<int> p;
void gener(int n)
{
	p.pb(2);
	for(int i=3;sz(p)<n;i++)
	{
		bool isp=true;
		for(int j=0;j<sz(p);j++)
			if(i%p[j]==0)
			{
				isp=false;
				break;
			}
		if(isp)
			p.pb(i);
	}
}
const ll INF=2e18;
ll pw(ll a,ll b){
	
	ll res = 1LL ;
	
	for( ; b ; b>>=1 , a*=a){
		if(b&1){
			res*=a;
			if(res>1e18 || res<0) return INF;
		}
		if(a>1e18 || res<0) return INF;	
	}
	return res;
		
}
ll pow_ub(ll a,ll b)
{
	return pw(a,b);
}
ll dp[1010];
int main()
{
	gener(12);
	int n;
	cin>>n;
	fill(dp,dp+n+1,INF);
	dp[1]=1;
	for(int i=0;i<12;i++)
		for(int j=n;j;j--)
			for(int k=1;(k+1)*j<=n&&pow_ub(p[i],k)!=INF&&pow_ub(p[i],k)<INF/dp[j];k++)
				if(dp[j]!=INF)
				{
//					cout<<i<<" "<<j<<" "<<k<<endl;
					dp[j*(k+1)]=min(dp[j*(k+1)],dp[j]*pow_ub(p[i],k));
				}
	cout<<dp[n]<<endl;
	return 0;
}