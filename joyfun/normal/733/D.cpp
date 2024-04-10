#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<long long,int> pii;
typedef vector<long long> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(long long i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (long long)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 100005;

int n, a[N][3];

struct Ans {
	int w, l, r;
	Ans() {}
	Ans(int w, int l, int r) : w(w), l(l), r(r) {}
	bool operator < (const Ans& c) const {
		return w < c.w;
	}
	void out() {
		if (l == r) printf("1\n%d\n", l);
		else printf("2\n%d %d\n", l, r);
	}
};

map<pair<int, int>, multiset<pair<int, int> > > h;

int cao(int a, int b, int c) {
	return min(a, min(b, c));
}

int main() {
	scanf("%d", &n);
	Ans ans; ans.w = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) scanf("%d", &a[i][j]);
		sort(a[i], a[i] + 3);
		ans = max(ans, Ans(a[i][0], i, i));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 3; k++) {
				int l = 3 - j - k;
				h[mp(a[i][j], a[i][k])].insert(mp(a[i][l], i));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 3; k++) {
				int l = 3 - j - k;
				h[mp(a[i][j], a[i][k])].erase(mp(a[i][l], i));
			}
		}
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 3; k++) {
				if (h[mp(a[i][j], a[i][k])].size() == 0) continue;
				int l = 3 - j - k;
				ans = max(ans, Ans(cao(a[i][j], a[i][k], a[i][l] + (--h[mp(a[i][j], a[i][k])].end())->first), i, (--h[mp(a[i][j], a[i][k])].end())->second));
			}
		}
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 3; k++) {
				int l = 3 - j - k;
				h[mp(a[i][j], a[i][k])].insert(mp(a[i][l], i));
			}
		}
	}
	ans.out();
	return 0;
}