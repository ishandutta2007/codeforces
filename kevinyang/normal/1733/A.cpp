#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        vector<int> a(N);
        vector<int> ans(K);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            ans[i % K] = max(ans[i % K], a[i]);
        }
        cout << accumulate(ans.begin(), ans.end(), 0LL) << '\n';
    }
}