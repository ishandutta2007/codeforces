#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
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

const int N = 200005;
bool vis[N];
vi con[N];
map<int,int> cols;
int color[N];
void dfs(int s)
{
    vis[s] = 1;
    cols[color[s]]++;
    for(int v:con[s])
        if(!vis[v])
            dfs(v);
}
int DFS(int n)
{
    int ans =0 ;
    for(int i = 1;i<=n;i++)
        if(!vis[i])
        {
            cols.clear();
            dfs(i);
            int add1 = 0,add2 = 0;
            for(auto x:cols)
                add1+=x.S,add2=max(add2,x.S);
            ans += add1 - add2;
        }
    return ans;    
}
int main()
{
    int n,m,k;
    sd(n),sd(m),sd(k);
    for(int i = 1;i<=n;i++)
        sd(color[i]);
    for(int i = 1;i<=m;i++)
    {
        int l,r;
        sd(l),sd(r);
        con[l].eb(r);
        con[r].eb(l);
    }
    cout<<DFS(n);
}