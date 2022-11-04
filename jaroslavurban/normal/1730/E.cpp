#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ST {
	int n;
	vector<vector<pair<int, int>>> jmp;
	ST(vector<int> a) : n(a.size()) {
		jmp.emplace_back(n);
		for (int i = 0; i < n; ++i) jmp[0][i] = {a[i], i};
		for (int pw = 1, l = 2; l <= n; ++pw, l *= 2) {
			jmp.emplace_back(n - l + 1);
			for (int j = 0; j < jmp.back().size(); ++j)
				jmp[pw][j] = max(jmp[pw - 1][j], jmp[pw - 1][j + l / 2]);
		}
	}
	pair<int, int> query(int l, int r) {
		int x = 31 - __builtin_clz(r - l);
		return max(jmp[x][l], jmp[x][r - (1 << x)]);
	}
};

const int M = 1e6 + 10;
vector<vector<int>> divs(M);

vector<int> get_prv(vector<int> a) {
	vector<int> last(M, -1), res(a.size());
	for (int i = 0; i < a.size(); ++i)
		res[i] = last[a[i]], last[a[i]] = i;
	return res;
}

vector<int> get_nxt(vector<int> a) {
	vector<int> last(M, a.size()), res(a.size());
	for (int i = (int)a.size() - 1; i >= 0; --i)
		res[i] = last[a[i]], last[a[i]] = i;
	return res;
}

vector<int> get_ps(vector<int> a) {
	vector<int> res(a.size());
	vector<pair<int, int>> st;
	for (int i = 0; i < a.size(); ++i) {
		while (st.size() && st.back().first >= a[i]) st.pop_back();
		res[i] = st.size() ? st.back().second : -1;
		st.push_back({a[i], i});
	}
	return res;
}

vector<int> get_pb(vector<int> a) {
	vector<int> res(a.size());
	vector<pair<int, int>> st;
	for (int i = 0; i < a.size(); ++i) {
		while (st.size() && st.back().first <= a[i]) st.pop_back();
		res[i] = st.size() ? st.back().second : -1;
		st.push_back({a[i], i});
	}
	return res;
}

vector<int> get_ns(vector<int> a) {
	vector<int> res(a.size());
	vector<pair<int, int>> st;
	for (int i = (int)a.size() - 1; i >= 0; --i) {
		while (st.size() && st.back().first >= a[i]) st.pop_back();
		res[i] = st.size() ? st.back().second : a.size();
		st.push_back({a[i], i});
	}
	return res;
}

vector<int> get_nb(vector<int> a) {
	vector<int> res(a.size());
	vector<pair<int, int>> st;
	for (int i = (int)a.size() - 1; i >= 0; --i) {
		while (st.size() && st.back().first <= a[i]) st.pop_back();
		res[i] = st.size() ? st.back().second : a.size();
		st.push_back({a[i], i});
	}
	return res;
}

ll solve1(vector<int> a) {
	auto nxt = get_nxt(a);
	auto prv = get_prv(a);
	auto ns = get_ns(a);
	auto nb = get_nb(a);
	auto ps = get_ps(a);
	auto pb = get_pb(a);
	vector<int> st, pos(M, -1);
	ll res = 0;
	for (int i = 0; i < a.size(); ++i) {
		while (st.size() && st.back() >= a[i]) {
			pos[st.back()] = -1;
			st.pop_back();
		}
		for (int div : divs[a[i]]) if (~pos[div]) {
			int left = max(0, pos[div] - max(pb[i], ps[pos[div]]));
			int right = max(0, min(min(nb[i], nxt[i]), min(ns[pos[div]], nxt[pos[div]])) - i);
			res += (ll)left * right;
		}
		st.push_back(a[i]);
		pos[a[i]] = i;
	}
	return res;
}

ll solve2(vector<int> a) {
	auto nxt = get_nxt(a);
	auto prv = get_prv(a);
	auto ns = get_ns(a);
	auto nb = get_nb(a);
	auto ps = get_ps(a);
	auto pb = get_pb(a);
	vector<int> st, pos(M, -1);
	ll res = 0;
	for (int i = (int)a.size() - 1; i >= 0; --i) {
		while (st.size() && st.back() >= a[i]) {
			pos[st.back()] = -1;
			st.pop_back();
		}
		for (int div : divs[a[i]]) if (~pos[div]) {
			int left = max(0, i - max(pb[i], max(prv[pos[div]], ps[pos[div]])));
			int right = max(0, min(min(nb[i], nxt[i]), ns[pos[div]]) - pos[div]);
			res += (ll)left * right;
		}
		st.push_back(a[i]);
		pos[a[i]] = i;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	for (int i = 1; i < M; ++i)
		for (int j = 2; j * i < M; ++j)
			divs[i * j].push_back(i);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& v : a) cin >> v;
		ll A = solve1(a);
		ll B = solve2(a);
		ll same = 0;
		for (int i = 0, j = 0; i < n; i = j) {
			while (j < n && a[i] == a[j]) ++j;
			same += (j - i) * ll(j - i + 1) / 2;
		}
		auto nxt = get_nxt(a);
		auto prv = get_prv(a);
		auto ns = get_ns(a);
		auto nb = get_nb(a);
		auto ps = get_ps(a);
		auto pb = get_pb(a);
		vector<bool> done(M);
		ST st(a);
		ll both = 0;
		for (int i = 0; i < n; ++i) if (!done[a[i]]) {
			for (int j = i; nxt[j] < n; j = nxt[j]) if (j + 1 < nxt[j] && ns[j] > nxt[j]) {
				auto [mx, idx] = st.query(j + 1, nxt[j]);
				if (mx % a[i]) continue;
				int left = max(0, j - max(ps[j], pb[idx]));
				int right = max(0, min(ns[nxt[j]], min(nb[idx], nxt[idx])) - nxt[j]);
				both += (ll)left * right;
			}
			done[a[i]] = true;
		}
		cout << A + B + same + both << '\n';
	}
}