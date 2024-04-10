#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll query(int t, int a, int b, int c) {
	cout << t << ' ' << a << ' ' << b << ' ' << c << '\n';
	ll ret; cin >> ret; fflush(stdout);
	return ret;
}

int main() {
	int N; cin >> N;

	vector<int> L, R;
	for (int i=3; i<=N; i++) {
		ll t = query(2, i, 1, 2);
		if (t == 1) L.push_back(i);
		else R.push_back(i);
	}

	vector<pll> La, Ra;
	for (int x : L) La.emplace_back(query(1, x, 1, 2), x);
	for (int x : R) Ra.emplace_back(query(1, x, 1, 2), x);
	pll Lmx = {0, 0}, Rmx = {0, 0};
	if (!La.empty()) Lmx = *max_element(La.begin(), La.end());
	if (!Ra.empty()) Rmx = *max_element(Ra.begin(), Ra.end());

	vector<pll> LL, LR, RL, RR;
	for (pll x : La) {
		if (x == Lmx) continue;
		ll t = query(2, x.vb, 1, Lmx.vb);
		if (t == 1) LL.push_back(x);
		else LR.push_back(x);
	}
	for (pll x : Ra) {
		if (x == Rmx) continue;
		ll t = query(2, x.vb, 2, Rmx.vb);
		if (t == 1) RL.push_back(x);
		else RR.push_back(x);
	}

	sort(RR.begin(), RR.end());
	sort(RL.rbegin(), RL.rend());
	sort(LR.begin(), LR.end());
	sort(LL.rbegin(), LL.rend());

	vector<int> ans;
	ans.push_back(1);
	for (pll x : RR) ans.push_back(x.vb);
	if (Rmx.vb) ans.push_back(Rmx.vb);

	if (ans.size() >= 2 && ans[ans.size()-2] != 1 && ans.back() != 1 && query(2, 1, ans[ans.size()-2], ans.back()) == -1)
		swap(ans[ans.size()-2], ans.back());

	if (!RL.empty()) ans.push_back(RL[0].vb);
	if (ans.size() >= 2 && ans[ans.size()-2] != 1 && ans.back() != 1 && query(2, 1, ans[ans.size()-2], ans.back()) == -1)
		swap(ans[ans.size()-2], ans.back());

	for (int i=1; i<RL.size(); i++) ans.push_back(RL[i].vb);

	ans.push_back(2);
	for (pll x : LR) ans.push_back(x.vb);
	if (Lmx.vb) ans.push_back(Lmx.vb);

	if (ans.size() >= 2 && ans[ans.size()-2] != 1 && ans.back() != 1 && query(2, 1, ans[ans.size()-2], ans.back()) == -1)
		swap(ans[ans.size()-2], ans.back());

	if (!LL.empty()) ans.push_back(LL[0].vb);
	if (ans.size() >= 2 && ans[ans.size()-2] != 1 && ans.back() != 1 && query(2, 1, ans[ans.size()-2], ans.back()) == -1)
		swap(ans[ans.size()-2], ans.back());

	for (int i=1; i<LL.size(); i++) ans.push_back(LL[i].vb);

	cout << 0 << ' ';
	for (ll x : ans) cout << x << ' ';


}