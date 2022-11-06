#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
typedef long double ld;
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// ll mod=67280421310721;
const ll mod=998244353;
// const ll mod=1e9+7;
ll INF=1e18;
const ll N=300005;
ll po(ll a,ll b)
{
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
ll a[100000][2];
ll b[100000][2];
int n,k;
ll m,o;
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
    while(test--)
    {
        cin>>n>>m;
        FOR(i,0,n)
        {
        	cin>>a[i][0];
        	a[i][1]=1;
        	while((a[i][0]%m)==0)
        	{
        		a[i][0]/=m;
        		a[i][1]*=m;
        	}
        }
        cin>>k;
        FOR(i,0,k)
        {
        	cin>>b[i][0];
        	b[i][1]=1;
        	while((b[i][0]%m)==0)
        	{
        		b[i][0]/=m;
        		b[i][1]*=m;
        	}
        }
        int i=0,j=0;
        while(i<n && j<k)
        {
        	if(a[i][0]!=b[j][0])
        	{
        		break;
        	}
        	o=min(a[i][1],b[j][1]);
        	a[i][1]-=o;
        	b[j][1]-=o;
        	if(a[i][1]==0)
        	{
        		i++;
        	}
        	if(b[j][1]==0)
        	{
        		j++;
        	}
        }
        if(i==n && j==k)
        {
        	cout<<"Yes\n";
        }
        else
        {
        	cout<<"No\n";
        }
    }
    return 0;
}