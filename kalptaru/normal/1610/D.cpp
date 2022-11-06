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
// const ll mod=998244353;
const ll mod=1e9+7;
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
        int a,c;
        ll cnt[32]={0},ans=0;
        FOR(i,0,n)
        {
            cin>>a;
            c=0;
            while((a%2)==0 && a>0)
            {
                c++;
                a>>=1;
            }
            cnt[c]++;
        }
        ll o=n-cnt[0];
        ans=(po(2,o)*(po(2,cnt[0])-1+mod))%mod;
        FOR(i,1,32)
        {
            if(cnt[i]==0)
            {
                continue;
            }
            o-=cnt[i];
            ans=(ans+(po(2,cnt[i]-1)-1)*po(2,o))%mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}