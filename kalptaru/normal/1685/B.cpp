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
        // cout<<'\n'<<'\n'<<test<<'\n';
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a+=(c+d);
        b+=(c+d);
        string s;
        cin>>s;
        int n=s.size();
        FOR(i,0,n)
        {
            if(s[i]=='A')
            {
                a--;
            }
            else
            {
                b--;
            }
        }
        if(a!=0 || b!=0)
        {
            cout<<"NO\n";
            continue;
        }
        int cn=0,o=0;
        vector<int> e,f;
        FOR(i,1,n)
        {
            if(s[i]!=s[i-1])
            {
                cn++;
            }
            else
            {
                if(cn%2)
                {
                    if(s[i-1]=='B')
                    {
                        e.pb((cn/2)+1);
                    }
                    else
                    {
                        f.pb((cn/2)+1);
                    }
                }
                else
                {
                    o+=(cn/2);
                }
                cn=0;
            }
        }
        if(cn%2)
        {
            if(s[n-1]=='B')
            {
                e.pb((cn/2)+1);
            }
            else
            {
                f.pb((cn/2)+1);
            }
        }
        else
        {
            o+=(cn/2);
        }
        sort(e.begin(), e.end());
        sort(f.begin(), f.end());
        int x=0,y=0;
        while(x<e.size() && c>0)
        {
            cn=min(c,e[x]);
            e[x]-=cn;
            c-=cn;
            x++;
        }
        while(y<f.size() && d>0)
        {
            cn=min(d,f[y]);
            f[y]-=cn;
            d-=cn;
            y++;
        }
        // cout<<e.size()<<' '<<f.size()<<'\n';
        if(c>0 && d>0)
        {
            if((c+d)>o)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
            continue;
        }
        if(c>0)
        {
            y=f.size()-1;
            while(y>=0 && f[y]>0 && c>0)
            {
                c-=f[y]-1;
                y--;
            }
            if(c>o)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
            continue;
        }
        if(d>0)
        {
            y=e.size()-1;
            while(y>=0 && e[y]>0 && d>0)
            {
                d-=e[y]-1;
                y--;
            }
            if(d>o)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}