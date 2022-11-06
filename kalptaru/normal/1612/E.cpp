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
// ll mod=67280421310721;
const ll mod=998244353;
// const ll mod=1e9+7;
ll INF=1e18;
const ll N=200005;
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
bool c(pair<ll,int> a,pair<ll,int> b)
{
    return a.ff>b.ff;
}
pair<ll,int> s[20][N];
bool ch[N];
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
    // cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        ll m[n],k[n];
        FOR(i,0,N)
        {
            FOR(j,0,20)
            s[j][i]=mp(0,i);
        }
        FOR(i,0,n)
        {
            cin>>m[i]>>k[i];
            FOR(j,0,20)
            {
                s[j][m[i]].ff+=min(j+1,k[i]);
            }
        }
        FOR(i,0,20)
        {
            sort(s[i],s[i]+N,c);
        }
        ld ma=0,a,l;
        int mi;
        FOR(i,0,20)
        {
            a=0;
            FOR(j,0,i+1)
            {
                a+=s[i][j].ff;
            }
            // cout<<a<<' ';
            l=(i+1);
            a=a/l;
            if(a>=ma)
            {
                ma=a;
                mi=i+1;
            }
        }
        cout<<mi<<'\n';
        FOR(i,0,mi)
        {
            cout<<s[mi-1][i].ss<<' ';
        }
    }
    return 0;
}