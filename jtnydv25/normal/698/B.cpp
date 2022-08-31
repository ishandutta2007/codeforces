#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int N = 2e5+10;
int a[N];
bool vis[N];
map<int,int> vertices;
vii cyc;
int main()
{
    int n;
    sd(n);
    rep(i,1,n+1){
        sd(a[i]);
    }
    bool flag = 1;
    
    rep(i,1,n+1)
    {
        if(!vis[i])   
        {
            int u = i,cnt = 0;
            vertices.clear();   
            while(1)
            {
                if(!vis[u]){

                    vis[u] = 1;
                    vertices[u] = ++cnt;
                    u = a[u];
                    if(vertices[u]){
                        cyc.eb(mp(cnt-vertices[u]+1,u));
                        break;
                    }
                }
                else
                    break;
            }
        }
    }
    sort(cyc.begin(),cyc.end());
    int changes = 0;
    for(auto x:cyc)
    {
        if(a[x.S]!=cyc[0].S)
            changes++;
        a[x.S] = cyc[0].S;
    }
    pd(changes);
    rep(i,1,n+1)
    printf("%d ",a[i]);
}