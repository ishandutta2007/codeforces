#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct pt {
	ld x, y, z;
	pt() {}
	pt(ld x, ld y, ld z) : x(x), y(y), z(z) {}
	pt operator+(const pt& other) const {
		return {x + other.x, y + other.y, z + other.z};
	}
	pt operator-(const pt& other) const {
		return {x - other.x, y - other.y, z - other.z};
	}
	pt operator*(ld k) const {
		return {x * k, y * k, z * k};
	}
};

ld dist(const pt& a, const pt& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

const ld eps = 1e-9;

bool lt(ld a, ld b) {
	return b - a > eps;
}

bool gt(ld a, ld b) {
	return a - b > eps;
}

bool leq(ld a, ld b) {
	return b - a > -eps;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<pt> p(n + 1);
    for (int i = 0; i <= n; ++i) {
    	cin >> p[i].x >> p[i].y >> p[i].z;
    }

    ld vp, vs;
    cin >> vp >> vs;
    pt start;
    cin >> start.x >> start.y >> start.z;

    vector<ld> when(n + 1);
    when[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	when[i] = when[i - 1] + dist(p[i], p[i - 1]) / vs;
    }

    if (gt(dist(p[n], start), when[n] * vp)) {
    	cout << "NO\n";
    	return 0;
    }

    int i = -1;
    for (int j = 0; ; ++j) {
    	if (leq(dist(p[j + 1], start), when[j + 1] * vp)) {
    		i = j;
    		break;
    	}
    }

    ld lf = 0, rg = 1;
    for (int it = 0; it < 200; ++it) {
    	ld md = (lf + rg) / 2;
    	ld timer = when[i] + (when[i + 1] - when[i]) * md;
    	pt curr = p[i] + (p[i + 1] - p[i]) * md;
    	if (leq(dist(curr, start), timer * vp)) {
    		rg = md;
    	} else {
    		lf = md;
    	}
    }

    cout << "YES\n";
    cout << fixed;
    cout.precision(10);

    cout << when[i] + (when[i + 1] - when[i]) * lf << "\n";
    pt curr = p[i] + (p[i + 1] - p[i]) * lf;
    cout << curr.x << " " << curr.y << " " << curr.z << "\n";

}