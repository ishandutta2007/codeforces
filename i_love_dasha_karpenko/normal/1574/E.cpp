#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e6+7;
map<int,int> line[2],col[2];
int cnt[6] = {0,0,0,0,0,0},po[N];
ll res_col = 1,res_line = 1,rev,clk_cl[3],clk_ln[3];
const ll MOD = 998244353;
void add(int x,int y,int val,int delta){
    if (val==-1)
        return;
    {
    if ((x+y)%2!=val)
        cnt[0]+=delta;
    if ((x+y)%2==val)
        cnt[1]+=delta;
    if (x%2==val)
        cnt[2]+=delta;
    if (x%2!=val)
        cnt[3]+=delta;
    if (y%2==val)
        cnt[4]+=delta;
    if (y%2!=val)
        cnt[5]+=delta;
    }
    clk_ln[(!line[0].count(x))+(!line[1].count(x))]--;
    clk_cl[(!col[0].count(y))+(!col[1].count(y))]--;

    int xv = y&1,yv = x&1;
    line[val^xv][x]+=delta;
    col[val^yv][y]+=delta;

    if (line[val^xv][x]==0)
        line[val^xv].erase(x);
    if (col[val^yv][y]==0)
        col[val^yv].erase(y);
    clk_ln[(!line[0].count(x))+(!line[1].count(x))]++;
    clk_cl[(!col[0].count(y))+(!col[1].count(y))]++;

}
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
void solve(){
    po[0] = 1;

    for(int i = 1;i<N;++i)
        po[i] = po[i-1]*2%MOD;
    int n,m,k;
    cin>>n>>m>>k;
    clk_ln[2] = n;
    clk_cl[2] = m;
    rev = binpow(2,MOD-2);

    map<pair<int,int>,int> M;
    for(int i = 1;i<=k;++i){
        int x,y,t;
        cin>>x>>y>>t;
        if (!M.count({x,y}))
            M[{x,y}] = -1;
        add(x,y,M[{x,y}],-1);
        M[{x,y}] = t;
        add(x,y,M[{x,y}],1);
        ll res = 0;
        if (!clk_ln[0]){
            res = (res+po[clk_ln[2]])%MOD;
        }
        if (!clk_cl[0]){
            res = (res+po[clk_cl[2]])%MOD;
        }
        res -= (cnt[0]==0)+(cnt[1]==0);
        res = (res+MOD)%MOD;
        cout<<res<<endl;

    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}