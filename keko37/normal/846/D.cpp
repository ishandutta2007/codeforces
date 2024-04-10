#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 505;

int n, m, k, q;
int l[MAXN] [MAXN], s[MAXN] [MAXN];

struct pixel {
	int x, y, t;
	pixel () {
	}
	pixel (int _x, int _y, int _t) {
		x=_x; y=_y; t=_t;
	}
};

bool cmp (pixel p1, pixel p2) {
	return p1.t<p2.t;
}

vector <pixel> v;

int sum (int x1, int y1, int x2, int y2) {
	return s[x2] [y2]-s[x1-1] [y2]-s[x2] [y1-1]+s[x1-1] [y1-1];
}

bool f (int t) {
	memset(l, 0, sizeof l);
	for (int i=0; i<q; i++) {
		if (v[i].t>t) break;
		l[v[i].x] [v[i].y]=1;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			s[i] [j]=l[i] [j]+s[i-1] [j]+s[i] [j-1]-s[i-1] [j-1];
			if (i>=k && j>=k && sum(i-k+1, j-k+1, i, j)==k*k) return 1;
		}
	}
	return 0;
}

int main () {
	cin >> n >> m >> k >> q;
	for (int i=0; i<q; i++) {
		pixel p;
		cin >> p.x >> p.y >> p.t;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), cmp);
	int low=0, high=1000000007, mid;
	if (!f(high)) {
		cout << -1;
		return 0;
	}
	while (low<high) {
		mid=(low+high)/2;
		if (f(mid)) {
			high=mid;
		} else {
			low=mid+1;
		}
	}
	cout << low;
	return 0;
}