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
const ll mod=998244353;
// ll mod=1000000007;
ll INF=1e18+5;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    int test=1;
    // cin>>test;
    while(test--)
    {
       	int n1,n2,n3;
       	cin>>n1>>n2>>n3;
       	ll a,b,c;
       	ll m1,m2,m3;
       	m1=m2=m3=INF;
       	ll s1=0,s2=0,s3=0;
       	FOR(i,0,n1)
       	{
       		cin>>a;
       		s1+=a;
       		m1=min(m1,a);
       	}
       	FOR(i,0,n2)
       	{
       		cin>>b;
       		s2+=b;
       		m2=min(m2,b);
       	}
       	FOR(i,0,n3)
       	{
       		cin>>c;
       		s3+=c;
       		m3=min(m3,c);
       	}
       	ll o=s1+s2+s3,s=0;
       	s=max(s,o-2*s1);
       	s=max(s,o-2*s2);
       	s=max(s,o-2*s3);
       	s=max(s,o-2*(m1+m2));
       	s=max(s,o-2*(m1+m3));
       	s=max(s,o-2*(m2+m3));
       	cout<<s;
    }
    return 0;
}