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
typedef long long ll;
typedef int _I;
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
int n, k, t, pos, res_pos, o = 1;
priority_queue<pi> pq;
set<int> usemx;
set<int, greater<int>> usemn;
vector<int> ans;
int main() {
	doin();
	cin >> n >> k;
	ans.resize(n, 0);
	for (int i = 0; i < n; i++)
		cin >> t, pq.push({t, i}), usemn.insert(i), usemx.insert(i);
	while (!pq.empty()) {
//		cout << pq.top().first << "\n";
		res_pos = pos = pq.top().second;
		pq.pop();
		if (usemn.find(pos) == usemn.end())
			continue;
//		cout << pos << "_\n";
		for (int i = 0; i <= k; i++) {
			auto it = usemx.lower_bound(pos);
			if (it == usemx.end())
				break;
//			cout << *it << " ";
			ans[*it] = o;
			usemx.erase(it);
			usemn.erase(*it);
		}
		pos = res_pos;
		for (int i = 0; i < k; i++) {
			auto it = usemn.lower_bound(pos);
			if (it == usemn.end())
				break;
//			cout << *it << "mn ";
			ans[*it] = o;
			usemn.erase(it);
			usemx.erase(*it);
		}
//		cout << "\n";
		o = (o % 2) + 1;
	}
	for(auto& i : ans)
		cout << i;
//	<< " ";
	return 0;
}