#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 303, mod = 1000000007;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc;
	cin >> tc;
	while(tc--) {
		string s, st;
		cin >> s;
		for(auto i : s) {
			if(i == 'A' || st.empty()) st += i;
			else  {
				st.pop_back();
			}
		}
		cout << st.size() << '\n';
	}
}