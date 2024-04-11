#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e6 + 30;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n;
vi a;
vi bad;
bool check(int i) {
	if (i & 1) {
		if (i && a[i - 1] >= a[i])
			return false;
		if (i + 1 < a.size() && a[i + 1] >= a[i])
			return false;
	} else {
		if (i && a[i - 1] <= a[i])
			return false;
		if (i + 1 < a.size() && a[i + 1] <= a[i])
			return false;
	}
	return true;
}
bool checkall() {
	int ok = 1;
//	for(int i = 0; i <n ; i++) cout << a[i] << " "; cout << "\n";
	for(auto i : bad) ok &= check(i);
	return ok;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	for(int i = 0; i < n; i++) if(!check(i)) bad.pb(i);
	set<pi> tt;
	if(bad.size()>6) return cout << 0, 0;
	for(int i = 0; i < bad.size(); i++)
		for(int j = 0; j < n; j++) {
			swap(a[bad[i]], a[j]);
			if(checkall()&&check(j)) tt.insert(minmax(bad[i], j));
			swap(a[bad[i]], a[j]);
		}
	cout << tt.size();
}