#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
int n, ans, uml = 0, umr = 0;
char c;
list<int> l[27];
list<int> r[27];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c, l[c == '?' ? 26 : c - 'a'].pb(i);
	for (int i = 1; i <= n; i++)
		cin >> c, r[c == '?' ? 26 : c - 'a'].pb(i);
	for (int i = 0; i < 26; i++) {
		ans += min(l[i].size(), r[i].size());
		uml += max(int(l[i].size() - r[i].size()), 0);
		umr += max(int(r[i].size() - l[i].size()), 0);
	}
	ans += min(uml, int(r[26].size())) + min(umr, int(l[26].size()));
	uml = max(int(r[26].size()) - uml, 0);
	umr = max(int(l[26].size()) - umr, 0);
	ans += min(uml, umr);
	cout << ans << "\n";
	for (int i = 0; i < 26; i++) {
		while (!(l[i].empty() || r[i].empty()))
			cout << l[i].front() << " " << r[i].front() << "\n", l[i].pop_front(), r[i].pop_front();
	}
	for (int i = 0; i < 26; i++) {
		while (!(r[26].empty() || l[i].empty()))
			cout << l[i].front() << " " << r[26].front() << "\n", l[i].pop_front(), r[26].pop_front();
		while (!(l[26].empty() || r[i].empty()))
			cout << l[26].front() << " " << r[i].front() << "\n", l[26].pop_front(), r[i].pop_front();
	}
	while (!(l[26].empty() || r[26].empty()))
		cout << l[26].front() << " " << r[26].front() << "\n", l[26].pop_front(), r[26].pop_front();

}