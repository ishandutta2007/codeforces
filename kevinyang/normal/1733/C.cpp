#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        vector<pair<int, int>> ans;
        int e = 0;
        for (int i = N-1; i >= 0; --i){
            if (a[i] % 2 != a[0] % 2) continue;
            e = i;
            break;
        }
        for (int i = 0; i < e; ++i){
            if (a[i] % 2 != a[0] % 2) continue;
            ans.push_back({i, e});
            a[i] = a[e];
        }
        int cur = 0;
        for (int i = 0; i < N; ++i){
            if (a[i] % 2 == a[0] % 2){
                cur = i;
            }
            else{
                ans.push_back({cur, i});
                a[i] = a[cur];
            }
        }
        cout << ans.size() << '\n';
        for (auto [a, b] : ans){
            cout << a+1 << " " << b+1 << '\n';
        }
    }
}