//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mlg = 18, mod = 1e9 + 7;
struct fenwick {
	vi tree;
	int n;
	void init(int sz) {
		n = sz;
		tree.resize(n + 1);
	}
	void add(int i, int x) {
		while (i <= n) {
			tree[i] += x;
			i += i & -i;
		}
	}
	int get(int i) {
		int r = 0;
		while (i) {
			r += tree[i];
			i -= i & -i;
		}
		return r;
	}
	int get(int i, int j) {
		return get(j)-get(i-1);
	}
};
fenwick f;
vi __x;
int n;
map<int, vpi> hseg, vseg;
map<int, pair<vpi, vpi>> a;//op, vseg
ll ans = 0;
int compx(int x) {
	return upper_bound(all(__x), x) - __x.begin();
}
void rebuild(map<int, vpi> &m, bool v) {
	for(auto i : m) {
		vpi t;
		sort(all(i.second));
		for(auto j : i.second) {
//			cout << i.first << " " << j.first << " " << j.second << (v?'v':'h') << "\n";
			if(t.empty()||t.back().second<j.first) {
//				cout << "x\n";
				t.pb(j);
			} else {
//				cout << "x\n";
				t.back().second = max(t.back().second, j.second);
			}
		}
		for(auto j : t) {
//			cout << j.first << " = " << j.second << " " << j.second-j.first+1 << "\n";
			ans += j.second-j.first+1;
			if(v) {//y
//				cout << compx(j.first) << " ___ " << compx(j.second) << "\n";
				a[(i.first)].second.pb({compx(j.first), compx(j.second)});
			} else {//x
//				cout << compx(i.first) << " ___ "  << "\n";
				a[(j.first)].first.pb({compx(i.first), 1});
				a[j.second+1].first.pb({compx(i.first), -1});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int x1, x2, y1, y2, i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		__x.pb(x1), __x.pb(x2);
		if(x1==x2) {//hseg
			hseg[x1].pb({y1, y2});
		} else {
			vseg[y1].pb({x1, x2});
		}
	}
	sort(all(__x));
	__x.erase(unique(all(__x)), __x.end());
	f.init(400000);
	rebuild(vseg, 1);
	rebuild(hseg, 0);
	for(auto i : a) {
//		cout << i.first << ":\n";
		for(auto j : i.second.first) {
//			cout << j.first << "__" << j.second << "\n";
			f.add(j.first, j.second);
		}
//		for(int i = 1; i <= 3; i++) couts << f.get(i, i);
//		cout << '\n';
		for(auto j : i.second.second) {
//			cout << j.first << " => " << j.second << "\n";
			ans -= f.get(j.first, j.second);
		}

	}
	cout << ans << "\n";
}