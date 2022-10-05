#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

	auto chk = [&](ll n, ll m, vll a) {
		sort(all(a), greater<ll>());
		vll b;
		for(ll x : a) {
			if(m == 1 || x < 2 * n) break;
			if(m == 0) return 1;
			m -= 2;
			b.push_back(x - 2 * n);
		}
		for(ll x : b) {
			m -= x / n;
			if(m <= 0) return 1;
		}
		return 0;
	};

	ints(t);
	while(t--) {
		ints(n, m, k);
		vll a(k);
		for(ll &x : a) cin >> x;
		cout << (chk(n, m, a) || chk(m, n, a) ? "YES\n" : "NO\n");
	}

  return 0;
}