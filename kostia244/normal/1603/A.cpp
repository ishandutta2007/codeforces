#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &i : a) cin >> i;
        int ok = 1;
        for(int i = 1; i <= n; i++) {
            int cur = 0;
            for(int k = 1; k <= min(i, 100); k++)
                cur |= a[i-1]%(k+1) != 0;
            ok &= cur;
        }
        report(ok);
    });
}