#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define iiii pair<ii, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n;
int x, y, z, k;
int mx;
int par[maxN];
int sub[maxN];
struct Edge{
    int chi, par, wei, cst;
} a[maxN];
struct part{
    int w, ch;
} user;
vector<int> vc[maxN];
 
int dfs(int node, int pare){
    sub[node] = 0;
    par[node] = pare;
    for(int child : vc[node]){
        if(child == pare) continue;
        sub[node] += dfs(child, node);
    }
    if(sub[node] == 0) sub[node] = 1;
    return sub[node];
}
 
bool comp(part n1, part n2){
    return ((n1.w - n1.w / 2) * n1.ch < (n2.w - n2.w / 2) * n2.ch);
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        int sam = 0;
        int ans = 0;
        cin >> n >> mx;
        for1(i, 1, n){
            vc[i].clear();
        }
        for1(i, 1, n - 1){
            cin >> x >> y >> z; k = 1;
            vc[x].pb(y); vc[y].pb(x);
            a[i].chi = x; a[i].par = y;
            a[i].wei = z; a[i].cst = k;
        }
        dfs(1, 1);
        priority_queue<part, vector<part>, decltype(&comp)> pq1(comp);
        priority_queue<part, vector<part>, decltype(&comp)> pq2(comp);
        user.ch = 6; user.w = -6;
        pq1.push(user);
        pq2.push(user);
        for1(i, 1, n - 1){
            if(par[a[i].chi] != a[i].par) swap(a[i].par, a[i].chi);
            user.ch = sub[a[i].chi];
            user.w = a[i].wei;
            if(a[i].cst == 1) pq1.push(user);
            if(a[i].cst == 2) pq2.push(user);
            sam += user.ch * user.w;
        }
        // cout << sam << endl;
        while(sam > mx){
            part us1 = pq1.top(); pq1.pop();
            part us2 = pq2.top(); pq2.pop();
            int val1 = (us1.w - us1.w / 2) * us1.ch;
            int val2 = (us2.w - us2.w / 2) * us2.ch;
                 if(mx + val1 >= sam){
                ans += 1; break;
            }
            else if(mx + val2 >= sam){
                ans += 2; break;
            }
            else if(val1 * 2 > val2){
                ans += 1; sam -= val1; us1.w /= 2;
            }
            else{
                ans += 2; sam -= val2; us2.w /= 2;
            }
            pq1.push(us1);
            pq2.push(us2);
        }
        cout << ans << endl;
    }
}