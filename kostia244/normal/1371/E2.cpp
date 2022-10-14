#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<19;
int n, p;
vector<int> ans;
set<int> good;
map<int, int> cnt;
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // order_of_key, find_by_order
int ok(int v){
	v%= p;
	if(v < 0) v += p;
	return v;
}
void inc(int v) {
	v = ok(v);
	v = (p-v)%p;
	if(cnt[v]++ == 0) good.erase(v);
}
void dec(int v) {
	v = ok(v);
	v = (p-v)%p;
	if(--cnt[v] == 0) good.insert(v);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<int, vector<array<int, 2>>> ev;
	cin >> n >> p;
	int start = -(1<<30);
	vector<int> a(n);
	ordered_set f;
	for(auto &i : a) cin >> i, start = max(start,  i-(n-1));
	for(int i = 0; i < n; i++) f.insert({a[i], i});
	for(int i = 0; i < p; i++) good.insert(i);
	for(int j = 0; j < n; j++) inc(f.order_of_key({start+j+1, -(1<<30)})-(start+j));
	for(int j = 0, i = start; i <= start + n + p; i++) {
		if(good.count(i%p)) ans.push_back(i);
		dec(f.order_of_key({i+1, -(1<<30)})-i);
		inc(f.order_of_key({i+n+1, -(1<<30)})-i-n);
	}
	sort(all(ans));
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i << ' ';
	return 0;
}