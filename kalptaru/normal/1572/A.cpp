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
        vector<int> ef[n];
        int k[n],v;
        FOR(i,0,n)
        {
           cin>>k[i];
           FOR(j,0,k[i])
           {
               cin>>v;
               ef[v-1].pb(i);
           }
        }
        set<pair<int,int> >s;
        queue<pair<int,int> > q;
        pair<int,int > c,t;
        FOR(i,0,n)
        {
           s.insert(mp(k[i],i));
        }
        int ans=1;
        while(!s.empty() || !q.empty())
        {
            if(s.empty())
            {
                ans++;
                break;
            }
            t=*s.begin();
            s.erase(t);
            if((t.ff)!=0)
            {
                if(q.empty())
                {
                    ans=-1;
                    break;
                }
                else
                {
                    ans++;
                    while(!q.empty())
                    {
                        c=q.front();
                        q.pop();
                        s.insert(c);
                    }
                    s.insert(t);
                }
            }
            else
            {    
                int g=ef[t.ss].size();
                FOR(i,0,g)
                {
                    c=mp(k[ef[t.ss][i]],ef[t.ss][i]);
                    s.erase(c);
                    c.ff--;
                    k[ef[t.ss][i]]--;
                    if(k[ef[t.ss][i]]==0 && ef[t.ss][i]<t.ss)
                    {
                        q.push(c);
                    }
                    else
                    {
                        s.insert(c);
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}