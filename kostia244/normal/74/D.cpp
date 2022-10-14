//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 4e6 + 666, mlg = 18, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct cmp_by_len {
	bool operator()(const pi& a, const pi& b) const {
		return pi{(a.second-a.first), a.first} > pi{(b.second-b.first), b.first};
	}
};
set<pi> bypos;
set<pi, cmp_by_len> bylen;
set<int> present;
map<int, int> guys_coat;
oset coat_list;
bool empty(pi a) {
//	cerr << a.first << " " << a.second << endl;
	return a.first>a.second;
}
void insert(pi a) {
//	cerr << a.first << " " << a.second << endl;
	bypos.insert(a);
	bylen.insert(a);
}
void erase(pi a) {
	bypos.erase(a);
	bylen.erase(a);
}
void split(pi a, int guy) {
	int mid = (a.first+a.second+1)/2;
	erase(a);
	for(auto i : {pi{a.first, mid-1}, pi{mid+1, a.second}})
		if(!empty(i))
			insert(i);
//	cerr << guy << " :: " << mid << endl;
	guys_coat[guy] = mid;
	coat_list.insert(mid);
}
pair<pi, pi> get(int pos) {
	auto it = bypos.lower_bound({pos, pos});
	pair<pi, pi> ans;
	ans.second = it==bypos.end()?pi{-1000, -1000}:*it;
	if(it==bypos.begin()) {
		ans.first = {-1000, -1000};
	} else {
		ans.first = *--it;
	}
	return ans;
}
pi combine(pi a, pi b, int u) {
	if(a.second+1==b.first) {
		return {a.first, b.second};
	}
	return {u?2000000000:-10000, u?2000000000:-10000};
}
void merge(int guy) {
	int pos = guys_coat[guy];
	pair<pi, pi> t = get(pos);
	pi cur = {pos, pos};
//	cerr << guy << " : " << pos << endl;
	cur = min(cur, combine(t.first, cur, 1));
	cur = max(cur, combine(cur, t.second, 0));
	if(t.first.first==cur.first)
		erase(t.first);
	if(t.second.second==cur.second)
		erase(t.second);
	insert(cur);
	guys_coat.erase(guy);
	coat_list.erase(pos);
}
pi pull() {
	assert(bylen.size());
	return *bylen.begin();
}
void add_guy(int guy) {
	present.insert(guy);
	pi t = pull();
//	cout << guy << " " << t.first << " " << t.second << endl;
	split(t, guy);
}
void erase_guy(int guy) {
	present.erase(guy);
	merge(guy);
}
void new_guy(int i) {
//	cerr << i << endl;
	if(present.count(i)) {
//		cerr << "REMOVAL" << endl;
		erase_guy(i);
	} else {
		add_guy(i);
	}
}
int query(int i, int j) {
	j++;
	return coat_list.order_of_key(j)-coat_list.order_of_key(i);
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n, m, t, l, r;
	cin >> n >> m;
	insert({1, n});
	while(m--) {
		cin >> t;
		if(t) new_guy(t);
		else cin >> l >> r, cout << query(l, r) << endl;
//		for(auto i : bypos)
//			cout << i.first << " " << i.second << "\n";
//		cout << "=====";
	}
	return 0;
}