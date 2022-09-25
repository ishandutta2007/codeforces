#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
int p[maxn + 1], c[maxn + 1], vis[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n, ans = INT_MAX;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> p[i];
        for(int i = 1; i <= n; i += 1) cin >> c[i];
        for(int i = 1; i <= n; i += 1) vis[i] = 0;
        for(int i = 1; i <= n; i += 1) if(not vis[i]){
            vector<int> v;
            for(int x = i; not vis[x]; x = p[x]){
                v.push_back(x);
                vis[x] = 1;
            }
            for(int i = 1; i <= (int)v.size(); i += 1)
                if((int)v.size() % i == 0 and i < ans)
                    for(int j = 0; j < i; j += 1){
                        int ok = 1;
                        for(int k = j; k < (int)v.size() and ok; k += i)
                            ok &= c[v[k]] == c[v[j]];
                        if(ok) ans = min(ans, i);
                    }
        }
        cout << ans << "\n";
    }
    return 0;
}