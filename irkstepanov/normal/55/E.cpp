#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

struct pt {
	ll x, y;
	pt() {}
	pt(ll x, ll y) : x(x), y(y) {}
	pt operator-(const pt& other) const {
		return {x - other.x, y - other.y};
	}
};

ll dot(const pt& p, const pt& q) {
	return p.x * q.x + p.y * q.y;
}

ll cross(const pt& p, const pt& q) {
	return p.x * q.y - p.y * q.x;
}

int get(int lf, int rg, int n) {
	if (lf <= rg) {
		return rg - lf + 1;
	}
	return get(lf, n - 1, n) + get(0, rg, n);
}

int main() {
    
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
    	cin >> p[i].x >> p[i].y;
    }

    ll area = 0;
    for (int i = 0; i < n; ++i) {
    	area += cross(p[i], p[(i + 1) % n]);
    }
    area = abs(area);

    int tt;
    cin >> tt;

    while (tt--) {
    	pt q;
    	cin >> q.x >> q.y;
    	ll a = 0;
    	for (int i = 0; i < n; ++i) {
    		a += abs(cross(p[i] - q, p[(i + 1) % n] - q));
    	}
    	if (area != a) {
    		cout << "0\n";
    		continue;
    	}
    	ll ans = ll(n) * (n - 1) * (n - 2) / 6;
    	int j = 1;
    	while (cross(q - p[0], p[j + 1] - p[0]) > 0) {
    		++j;
    	}
    	ans -= ll(j) * (j - 1) / 2;
    	for (int i = 1; i < n; ++i) {
    		while (cross(q - p[i], p[(j + 1) % n] - p[i]) > 0) {
    			j = (j + 1) % n;
    		}
    		int cnt = get((i + 1) % n, j, n);
    		ans -= ll(cnt) * (cnt - 1) / 2;
    	}
    	cout << ans << "\n";
    }

    
}