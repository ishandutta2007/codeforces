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
        int n, m;
        cin >> n >> m;
        set<int> good;
        for(int i = 1; i <= n; i++) good.insert(i);
        for(int a, b, c, i = 0; i < m; i++) {
            cin >> a >> b >> c;
            if(good.count(b)) good.erase(b);
        }
        int v = *good.begin();
        for(int i = 1; i <= n; i++) if(i != v) {
            cout << i << " " << v << '\n';
        }
    }
}