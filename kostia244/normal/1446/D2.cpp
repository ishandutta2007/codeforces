#include <bits/stdc++.h>
//#define endl '\n'
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n), common;
    map<int, int> f;
    array<int, 2> com {0, 0};
    for(auto &i : a) { 
		cin >> i;
		com = max(com, {++f[i], i});
	}
    for(auto [v, fr] : f) if(fr > 500)
        common.push_back(v);
	int ans = 0;
	for(auto x : common) if(x^com[1]) {
		int run = n+1;
		vector<int> lst(2*n+2, -2);
		lst[run] = -1;
		for(int i = 0; i < n; i++) {
			if(a[i] == com[1]) run--;
			if(a[i] == x) run++;
			if(lst[run] != -2) ans = max(ans, i-lst[run]);
			else lst[run] = i;
		}
	}
    for(int A = 1; A <= 500; A++) {
        vector<int> fr(n+2);
        int oh = 0;
        for(int i = 0, j = 0; i < n; i++) {
            while(j < n && fr[a[j]] < A) {
                oh += ++fr[a[j]] == A;
                j++;
            }
            if(oh > 1) ans = max(ans, j-i);
            oh -= fr[a[i]]-- == A;
        }
    }
	cout << ans << endl;
    return 0;
}