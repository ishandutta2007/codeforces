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
	//multitest([&](){});
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> ops;
    for(int pos = 0, op = 1; op <= n; op++) {
        vector<int> cur;
        for(int i = k; i;) {
            int t = a[pos]%2 == 1 ? 2 : 1;
            a[pos] += min(t, i);
            t = min(t, i);
            i -= min(t, i);
            pos += a[pos]%2;
            if(pos == n) pos = 0;
        }
        int ok = 1;
        for(int i = 0; i < n; i++) ok &= a[i]%2;
        //for(auto i : a) cout << i << " "; cout << endl;
        if(k * *max_element(all(a)) <= op*k && ok) {
            pos = 0;
            int ans = 0, t;
            while(op--) {
                vector<int> cur, took(n);
                for(int i = 0; i < k; i++) {
                    int mx = 0;
                    while(took[mx]) mx++;
                    for(int j = 0; j < n; j++) if(a[j] > a[mx] && !took[j]) mx = j;
                    a[mx]--;took[mx] = 1;
                    cur.push_back(mx);
                }
                ops.push_back(cur);
            }
            for(auto i : ops) {
                cout << "? ";
                for(auto j : i) cout << j+1 << " "; cout << endl;
                cin >> t; ans ^= t;
            }
            cout << "! " << ans << endl;
            exit(0);
        }
    }
    cout << "-1\n";exit(0);
}