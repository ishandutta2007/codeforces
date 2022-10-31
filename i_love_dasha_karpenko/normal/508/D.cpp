#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef int ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef long double ld;
#define fi first
#define sc second
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
const ll DIM = 62+8;
const ll INF = 1E5;

ll gi(char &ch){
    if (ch>='a' && ch<='z')
    return ch-'a'+1;
    else if (ch>='0' && ch<='9') return ch-'0'+27;
    else return ch-'A'+37;
}

char tc(ll a){
    if (a<=26)
    return char(a+'a'-1);
    else if (a<=36) return char(a+'0'-27);
    else return char(a+'A'-37);
}
vector<pp> G[DIM][DIM];
ll in[DIM][DIM],out[DIM][DIM];
string ans;
void dfs(pp v){

    while(!G[v.fi][v.sc].empty()){
        pp to = G[v.fi][v.sc].back();
        G[v.fi][v.sc].pop_back();
        dfs(to);
    }
    ans+=tc(v.sc);
}
bool mc(pp a,pp b){
    return G[a.fi][a.sc].size()<G[b.fi][b.sc].size();
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cout<<ll('1')<<' '<<ll('a')<<endl;
    ll n;
    cin>>n;
    forn(i,n){
        string s;
        cin>>s;
        ll a = gi(s[0]);
        ll b = gi(s[1]);
        ll c = gi(s[2]);
        G[a][b].pb({b,c});
        out[a][b]++;
        in[b][c]++;
    }
    ll cnt = 0;
    ll flag = 0;
    pp start = {0,0};
    forn(i,62){
        forn(j,62){
            sort(G[i][j].begin(),G[i][j].end(),mc);
            if (abs(out[i][j]-in[i][j])>1)flag = 1;
            if (in[i][j]+out[i][j]==0)continue;
            if (start==pp{0,0})start = {i,j};
            if (out[i][j]-in[i][j]==1)start = {i,j};
            if (abs(out[i][j]-in[i][j])>0)cnt++;
        }
    }
    if (cnt<=2 && flag==0){

        dfs(start);
        ans+=tc(start.fi);
        reverse(ans.begin(),ans.end());
        if (ans.length()==n+2){
            cout<<"YES\n"<<ans<<endl;
            return 0;
        }
        cout<<"NO\n";
    }
    else cout<<"NO\n";

    return 0;
}