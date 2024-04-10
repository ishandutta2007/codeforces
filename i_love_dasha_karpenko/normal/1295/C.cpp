#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 10E4+7;
const ll INF = 10E17;
const ll MAXN = 29;
ll dp[DIM][30];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tt;
    cin>>tt;
    forn(q,tt){
        string s,t;
        cin>>s>>t;
        forn(i,MAXN)dp[s.length()][i] = -1;
        for(ll i = s.length()-1;i>=0;i--){
            forn(j,MAXN)dp[i][j] = dp[i+1][j];
            dp[i][s[i]-'a'+1] = i;
        }
        ll p = 0,res = 0,flag = 0;
        while(p<t.length()){
            ll pos = 0;
            res++;
            if (dp[pos][t[p]-'a'+1]==-1){
                flag = 1;
                break;
            }
            while(p<t.length() && pos<s.length()){
                if (dp[pos][t[p]-'a'+1]==-1)break;
                pos = dp[pos][t[p]-'a'+1]+1;
                p++;
            }
        }
        if (flag==1)cout<<"-1\n";
        else cout<<res<<endl;
    }
    return 0;
}
// 9 7+2