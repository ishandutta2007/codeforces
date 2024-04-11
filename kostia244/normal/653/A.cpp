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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vi a;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	for(int i = 2; i < a.size(); i++) {
		if(a[i-1]==a[i]-1&&a[i-2]==a[i]-2) return cout << "YES", 0;
	}
	cout << "NO";
}