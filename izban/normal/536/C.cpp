#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "tavas"

struct pt {
	ll x, y;
	int id;

	pt() {}


	bool operator< (const pt &p) const {
		if (x != p.x) return x > p.x;
		return y > p.y;
	}

	bool operator== (const pt &p) const {
		return x == p.x && y == p.y;
	}

	void print() const {
		cout << x << " " << y << endl;
	}
};

ll turn(pt A, pt B, pt C) {
	return (A.x - B.x) * (B.y - C.y) * A.y * C.x - (B.x - C.x) * (A.y - B.y) * A.x * C.y;
}

int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#else
	//    freopen(task".in", "r", stdin);
	//    freopen(task".out", "w", stdout);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<pt> a(n);
		for (int i = 0; i < n; i++) {
			int xx, yy;
			scanf("%d%d", &xx, &yy);
			a[i].x = xx;
			a[i].y = yy;
			a[i].id = i;
		}

		sort(a.begin(), a.end());
		vector<pt> aa = a;
		a.resize(unique(a.begin(), a.end()) - a.begin());
		pt p1 = a[0];
		pt p2 = a[0];
		for (int i = 0; i < n; i++) if (a[i].y > p2.y || a[i].y == p2.y && a[i].x > p2.x) p2 = a[i];

		vector<pt> vct;
		for (int i = 0; i < n; i++) if (!(p1 == p2)) {
			if (a[i] == p1 || a[i] == p2 || turn(p1, p2, a[i]) <= 0) {
				while (vct.size() > 1 && turn(vct[(int)vct.size() - 2], vct.back(), a[i]) < 0) {
					vct.pop_back();
				}
				vct.push_back(a[i]);
			}
		}

		vector<char> f(n);
		set<pt> st;
		st.insert(p1);
		st.insert(p2);
		for (pt p : vct) st.insert(p);
		a = aa;
		for (int i = 0; i < n; i++) {
			if (st.find(a[i]) != st.end()) {
				f[i] = 1;
			}
		}

		vector<int> ans;
		for (int i = 0; i < n; i++) if (f[i]) ans.push_back(a[i].id + 1);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < (int)ans.size(); i++) printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
	}

	return 0;
}