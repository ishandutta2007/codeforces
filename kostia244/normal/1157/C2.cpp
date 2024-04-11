#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}

template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}

typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, lst, tn;
vi v, t;
string ans, l = "L", r = "R";

int _l(int i) {
	if (v[i] <= lst)
		return 0;
	for (int j = i+1; j < tn; l+="L", j++)
		if (v[j] <= v[j - 1])
			return j-i;
	return tn - i;
}
int _r(int i) {
	if (v[i] <= lst)
		return 0;
	for (int j = i-1; j >= 0; r += "R", j--)
		if (v[j] <= v[j + 1])
			return i-j;
	return i+1;
}

int main() {
	doin();
	cin >> n;
	tn = n;
	lst = -1;
	getv(v, n);
	int i = 0, j = n - 1;
	while (n--) {
		if (v[i] > lst && v[i] == v[j]) {
			if(_l(i) > _r(j))
				ans += l;
			else
				ans += r;
			break;
		} else if (min(v[i], v[j]) > lst) {
			if (v[i] < v[j])
				ans += "L", lst = v[i++];
			else
				ans += "R", lst = v[j--];
		} else if (max(v[i], v[j]) > lst) {
			if (v[i] < v[j])
				ans += "R", lst = v[j--];
			else
				ans += "L", lst = v[i++];
		} else
			break;

	}
	cout << ans.size() << "\n" << ans;
}