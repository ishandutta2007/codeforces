#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
void solve() {
		int n;
		cin >> n;
		vector<int> a(n), b;
		for(auto &i : a) cin >> i;
		b = a, sort(all(b));
		for(auto &i : a) i = lower_bound(all(b), i) - b.begin();
		RMQ mn(a);
		for(auto &i : a) i *= -1;
		RMQ mx(a);
		for(auto &i : a) i *= -1;
		int Fm = -1;
		for(int i = 0; i < n; i++) {
			Fm = max(Fm, a[i]);
			int A = i;
			int B = i;
			for(int z = 1<<20; z>>=1;) {
				if(A+z < n && mn.query(i+1, A+z+1) > Fm) A += z;
				if(B+z < n && mn.query(i+1, B+z+1) >= Fm) B += z;
			}
			++A;
			int C = n, D = n;
			for(int z = 1<<20; z>>=1;) {
				if(C-z >= 0 && -mx.query(C-z, n) < Fm) C -= z;
				if(D-z >= 0 && -mx.query(D-z, n) <= Fm) D -= z;
			}
			A++, B++;
			--C;
			int L = max(A, D), R = min(B, C);
			if(L <= R) {
				cout << "YES\n";
				cout << i+1 << " " << L-i-1 << " " << n-L << '\n';
				return;
			}
		}
		cout << "NO\n";
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}