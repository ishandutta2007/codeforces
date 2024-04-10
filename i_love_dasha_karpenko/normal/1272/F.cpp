#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long   ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 200+7;
const ll INF = 2E9;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

struct node{
    ll fi,sc,th;
};
ll dp[DIM][DIM][DIM*2];
node P[DIM][DIM][DIM*2];
string s,t;
ll solve(ll a,ll b,ll dif){
    if (dif>=DIM*2)return INF;
    if (dp[a][b][dif]!=-1)return dp[a][b][dif];


    dp[a][b][dif] = INF;
    if (dif>0){
        ll pos1 = a;
        ll pos2 = b;
        if (pos1>0 && s[a-1]=='(')pos1--;
        if (pos2>0 && t[b-1]=='(')pos2--;
        if (dp[a][b][dif]>solve(pos1,pos2,dif-1)+1){
            dp[a][b][dif]=solve(pos1,pos2,dif-1)+1;
            P[a][b][dif] = {pos1,pos2,dif-1};
        }
    }
    if (a>0 || b>0){
        ll pos1 = a;
        ll pos2 = b;
        if (pos1>0 && s[a-1]==')')pos1--;
        if (pos2>0 && t[b-1]==')')pos2--;
        if (dp[a][b][dif]>solve(pos1,pos2,dif+1)+1){
            dp[a][b][dif]=solve(pos1,pos2,dif+1)+1;
            P[a][b][dif] = {pos1,pos2,dif+1};
        }
    }
    return dp[a][b][dif];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>s>>t;
    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = 0;
    solve(s.length(),t.length(),0);
    vector<char> ans;
    node cur = {s.length(),t.length(),0};
    while(cur.fi!=0 || cur.sc!=0 || cur.th!=0){
        if (cur.th==P[cur.fi][cur.sc][cur.th].th-1)ans.pb(')');
        else ans.pb('(');
        cur = P[cur.fi][cur.sc][cur.th];
    }
    reverse(ans.begin(),ans.end());
    for(char to:ans)cout<<to;
    cout<<endl;
    return 0;
}
// 11 - 8 11-8+1-3 = 1
// 11 10 8