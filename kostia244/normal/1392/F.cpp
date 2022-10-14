#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<array<ll, 2>> st;
void add(ll a) {
	//cout << a << "::" << endl;
	while(true) {
		//cout << a << ":" << endl;
		//for(auto [l, r] : st) cout << l << " " << r << endl;
		if(st.empty() || st.back()[1] == a) {
			st.push_back({a, a});
			break;
		}
		//cout << "end\n";
		//cout << st.back()[1] << " vs " << a+1 << endl;
		if(st.back()[1] == a+1) {
			st.back()[1]--;
			break;
		}
		//cout << st.back()[1] << " vs " << a+1 << endl;
		ll d = min(st.back()[1] - a - 1, st.back()[0]-st.back()[1]);
		if(st.size() == 1) {
			ll op = 0, LEN = st.back()[0]-st.back()[1]+1;
			//cout << st.back()[0] << " - " << st.back()[1] << " | " << LEN << endl;
			for(ll z = 1ll<<50; z>>=1;) {
				ll t = (op+z);
				if(st.back()[1] - (t/LEN) > a+t) op = t;
			}
			if(st.back()[1]-(op/LEN)-(a+op) == 2) op++;
			st.back()[0] -= op/LEN;
			st.back()[1] -= op/LEN;
			a += op;
			//cout << op << endl;
			op%=LEN;
			if(op) {
				ll L = st.back()[0], R = st.back()[1];
				st.pop_back();
				st.push_back({L-1, L-op});
				st.push_back({L-op, R});
			}
			//cout << st.back()[0] << " " << st.back()[1] << " " << a << endl;
		} else if(d == 0) {
			st.pop_back();
			st.back()[1]--;
			a++;
			//cout << "CASE " << st.back()[0] << " " << st.back()[1] << " " << a << " | " << st.size() << endl;
		} else {
			int S = st.size();
			st[S-1][0] -= d;
			st[S-2][1] -= d;
			//cout << "HERE " << d << endl;
			a += d;
		}
		//cout << "NEXT\n";
	}
	//for(auto [l, r] : st) cout << l << " " << r << endl;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	reverse(all(a));
	for(auto &i : a) add(i);
	vector<ll> ans;
	for(auto i : st)
		while(i[0] >= i[1]) ans.push_back(i[0]--);
	reverse(all(ans));
	for(auto &i : ans) cout << i << " "; cout << endl;
}