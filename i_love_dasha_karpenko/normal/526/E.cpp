#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E6+7;
const int LOG = 21;
int A[N],P[N],depth[N],tin[N],tout[N],timer;
vector<int> G[N];
void dfs(int v){
    tin[v] = ++timer;
    for(int to:G[v])
        dfs(to);
    tout[v] = ++timer;
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    while(q--){
        ll sz;
        cin>>sz;
        ll sum = 0,ptr = 1;
        for(int i = 1;i<=n;++i){
            sum+=A[i];
            while(sum>sz){
                sum-=A[ptr];
                ++ptr;
            }
            P[i] = ptr-1;
            depth[i] = depth[ptr-1]+1;
            if (ptr-1>0)
                G[ptr-1].push_back(i);
        }
        if (ptr==1){
            cout<<1<<endl;
        }
        else {
            timer = 0;
            for (int i = 1; i <= n; ++i) {
                if (!tin[i])
                    dfs(i);
            }
            ptr = n, sum = 0;
            while (ptr > 1 && A[ptr] + sum <= sz) {
                sum += A[ptr];
                --ptr;
            }
            ++ptr;

            int res = n;
            int p = 2;
            for (int i = 1; i <= n; ++i) {
                sum += A[i];
                while (sum > sz && ptr <= n) {
                    sum -= A[ptr];
                    ++ptr;
                }
                if (sum > sz)
                    break;
                p = max(p, i + 1);
                while (!(tin[p] <= tin[ptr - 1] && tout[ptr - 1] <= tout[p]))
                    ++p;
                res = min(res, 1 + depth[ptr - 1] - depth[p] + 1);
            }
            cout << res << endl;
        }
        for(int i = 1;i<=n;++i){
            tin[i] = tout[i] = 0;
            G[i].clear();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}