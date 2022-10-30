#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
const int N = 2e5+7;
int A[N],cnt[N],vis[N];
bool flag;
vector<int> G[N];
int mx;
void dfs(int v){
    vis[v] = 1;
    for(int to:G[v]){
        if (vis[to]==2 || to==mx){
            continue;
        }
        if (vis[to]==1){
            flag = 1;
            return;
        }
        dfs(to);
    }
    vis[v] = 2;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        G[i].clear();
        cnt[i] = 0;
        vis[i] = 0;
    }
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        ++cnt[A[i]];
    }
    for(int i = 1;i<=n;++i){
        int b;
        cin>>b;
        G[A[i]].push_back(b);
    }
    mx = 1;
    flag = 0;
    for(int i = 1;i<=n;++i){
        if (cnt[i]>cnt[mx]){
            mx = i;
        }
    }
    for(int i = 1;i<=n;++i){
        if (i==mx){
            continue;
        }
        if (!vis[i]){
            dfs(i);
        }
    }
    if (flag){
        cout<<"WA\n";
    }
    else{
        cout<<"AC\n";
    }

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}