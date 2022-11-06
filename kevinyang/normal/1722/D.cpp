#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a;
        ll ans = 0;
        for (int i = 1; i <= N; ++i){
            char c; cin >> c;
            int l = i-1;
            int r = N-i;
            if (c == 'L') a.push_back(r-l), ans += l;
            if (c == 'R') a.push_back(l-r), ans += r;
            a.push_back(0);
        }
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < N; ++i){
            ans += a[i];
            cout << ans << " ";
        }
        cout << '\n';
    }
}