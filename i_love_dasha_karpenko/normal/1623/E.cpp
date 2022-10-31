//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int N = 3e5+7;
char A[N];
int l[N],r[N],tin[N],in_pos[N],timer = 0;

void dfs(int v){
    if (v==0)
        return;
    dfs(l[v]);
    tin[v] = ++timer;
    in_pos[timer] = v;
    dfs(r[v]);
}
string ans = "";
bool need[N];
int k;
bool solve(int v,bool pnt,int to_paint){
    if (v==0)
        return 0;
    pnt&=(to_paint<k);
    bool col = solve(l[v],pnt,(to_paint+1)*pnt);
    col |= (need[v]&pnt);
    ans+=A[v];
    if (col)
        ans+=A[v];
    k-=col;
    solve(r[v],col,(to_paint)*col);
    return col;
}
void solve() {
    int n;
    cin>>n>>k;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    for(int i = 1;i<=n;++i)
        cin>>l[i]>>r[i];
    dfs(1);
    for(int i = n-1;i>=1;--i){
        need[in_pos[i]] = A[in_pos[i+1]]>A[in_pos[i]] || (A[in_pos[i+1]]==A[in_pos[i]] && need[in_pos[i+1]]);
    }
    solve(1,1,0);
    cout<<ans<<endl;
}

signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}