#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        auto check = [](int x) {
            for(int j = 2; j*j <= x; j++)
                if(x%j == 0) return 1;
            return 0;
        };
        int sm = 0;
        for(auto &i : a) cin >> i, sm += i;
        if(check(sm)) {
            cout << n << '\n';
            for(int i = 1; i <= n; i++) cout << i << " "; cout << '\n';
        } else {
            cout << n-1 << '\n';
            int od = 0, pos = 1;
            for(auto &i : a) {
                if(i%2 == 1 && od == 0) od = 1;
                else cout << pos << " ";
                pos++;
            }
            cout << '\n';
        }
    }
}