#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=1000000007;
ll INF=1e18;
ll po(ll a,ll b){
	ll re=1;  
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
bool ch[4000000];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	
	ll test=1;
	cin>>test;
	FOR(gtest,0,test)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int u=min(21,k);
		int p=1<<u;
		int x=0;
		int o[n-k+1];
		FOR(j,0,u)
		{
			x<<=1;
			if(s[n+j-u]=='1')
			{
				x++;
			}
		}
		int cnt=0;
		FORD(j,n-u,n-k)
		{
			if(s[j]=='0')
				cnt++;
		}
		o[0]=x^(p-1);
		if(cnt==0)
			ch[x^(p-1)]=1;
		FORD(i,n-1,k-1)
		{
			x>>=1;
			if(s[i-u+1]=='1')
			{
				x+=(p/2);
			}
			else
			{
				cnt--;
			}
			if(s[i-k+1]=='0')
			{
				cnt++;
			}
			o[n-i-1]=x^(p-1);
			if(cnt==0)
			ch[x^(p-1)]=1;
		}
		// cout<<'\n';
		int ans=-1;
		FOR(i,0,p)
		{
			if(ch[i]==0)
			{
				ans=i;
				break;
			}
		}
		FOR(i,0,n-k+1)
		{
			ch[o[i]]=0;
		}
		if(ans==-1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			FOR(i,0,k-u)
				cout<<'0';
			p>>=1;
			// cout<<ans<<' '<<p<<' ';
			FOR(i,0,u)
			{
				if(ans>=p)
				{
					cout<<'1';
					ans-=p;
				}
				else
				{
					cout<<'0';
				}
				p>>=1;
			}
			cout<<'\n';
		}
	}
	return 0;
}