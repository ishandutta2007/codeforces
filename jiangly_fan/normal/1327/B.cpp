#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int mat[maxn + 1], vis[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i += 1) vis[i] = 0;
        for(int i = 1, k; i <= n; i += 1){
            cin >> k;
            mat[i] = 0;
            for(int g; k; k -= 1){
                cin >> g;
                if(not vis[g] and not mat[i]){
                    mat[i] = g;
                    vis[g] = 1;
                }
            }
            if(not mat[i]) ans = i;
        }
        if(not ans) cout << "OPTIMAL\n";
        else for(int j = 1; j <= n; j += 1) if(not vis[j]){
            cout << "IMPROVE\n" << ans << " " << j << "\n";
            break;
        }
    }
    return 0;
}