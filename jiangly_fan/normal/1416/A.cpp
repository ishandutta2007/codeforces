#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
vector<int> p[maxn];
int ans[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) p[i].clear();
        for(int i = 1, a; i <= n; i += 1){
            cin >> a;
            p[a].push_back(i);
        }
        int f = n + 1;
        for(int i = 1; i <= n; i += 1) if(not p[i].empty()){
            int d = max(p[i][0], n + 1 - p[i].back());
            for(int j = 1; j < p[i].size(); j += 1) d = max(d, p[i][j] - p[i][j - 1]);
            for(int j = d; j < f; j += 1) ans[j] = i;
            f = min(d, f);
        }
        for(int i = 1; i < f; i += 1) ans[i] = -1;
        for(int i = 1; i <= n; i += 1) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}