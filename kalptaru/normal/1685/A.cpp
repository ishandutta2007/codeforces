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
    // int gt=0;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int a[n];
        FOR(i,0,n)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int c=1,m=0,j=0;
        FOR(i,1,n)
        {
            if(a[i]==a[i-1])
            {
                c++;
            }
            else
            {
                if(c>m)
                {
                    j=i;
                }
                m=max(c,m);
                c=1;
            }
        }
        if(c>m)
        {
            j=n;
        }
        m=max(m,c);
        int o=n/2;
        if(m>o || n%2)
        {
            cout<<"NO\n";
            continue;
        }
        if(m==o && j!=n && j!=o)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";  
        FOR(i,0,n)
        {
            if(i%2)
            {
                cout<<a[i/2+o]<<' ';
            }
            else
            {
                cout<<a[i/2]<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}