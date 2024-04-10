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
        string s;
        cin>>s;
        n=2*n;
        int a[n];
        int c=0;
        bool f=1;
        FOR(i,0,n)
        {
            if(s[i]=='(')
            {
                c++;
            }
            else
            {
                c--;
                if(c<0)
                {
                    f=0;
                }
            }
            a[i]=c;
            // cout<<a[i]<<' ';
        }
        // cout<<'\n';
        if(f)
        {
            cout<<"0\n";
            continue;
        }
        int x=0,y=0,yi=n-1,xi=-1;
        FOR(i,0,n)
        {
            if(a[i]<0)
            {
                break;
            }
            else
            {
                if(a[i]>x)
                {
                    xi=i;
                    x=a[i];
                }
            }
        }
        FORD(i,n,0)
        {
            if(a[i]<0)
            {
                break;
            }
            else
            {
                if(a[i]>y)
                {
                    yi=i;
                    y=a[i];
                }
            }
        }
        int m=x,mi=xi;
        FOR(i,xi+1,yi)
        {
            if(a[i]>m)
            {
                mi=i;
                m=a[i];
            }
        }
        if(m>(x+y))
        {
            cout<<2<<'\n';
            cout<<1<<' '<<mi+1<<'\n';
            cout<<mi+2<<' '<<n<<'\n';
        }
        else
        {
            cout<<1<<'\n';
            cout<<xi+2<<' '<<yi+1<<'\n';
        }
    }
    return 0;
}