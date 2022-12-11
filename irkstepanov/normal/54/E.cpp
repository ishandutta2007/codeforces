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

struct pt{
	ld x, y;
	pt() {}
	pt(ld x, ld y) : x(x), y(y) {}
	pt operator-(const pt& other) const {
		return {x - other.x, y - other.y};
	}
	pt operator+(const pt& other) const {
		return {x + other.x, y + other.y};
	}
	pt operator*(ld k) const {
		return {x * k, y * k};
	}
};

ld dot(const pt& p, const pt& q) {
	return p.x * q.x + p.y * q.y;
}

ld cross(const pt& p, const pt& q) {
	return p.x * q.y - p. y * q.x;
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

    for (int i = 0; i < n; ++i) {
    	if (dot(p[i] - p[(i + 1) % n], p[(i + 2) % n] - p[(i + 1) % n]) >= 0) {
    		cout << "0\n";
    		return 0;
    	}
    }

    ld ans = 1e18;
    for (int step = 0; step < 2; ++step) {
    	pt dir = p[1] - p[0];
    	int j = 0;
    	for (int k = 0; k < n; ++k) {
    		if (dot(p[k], dir) > dot(p[j], dir)) {
    			j = k;
    		}
    	}
    	ld curr = 0;
    	for (int i = 2; i <= j; ++i) {
    		curr += abs(cross(p[i - 1] - p[0], p[i] - p[0]));
    	}
    	for (int i = 0; i < n; ++i) {
    		dir = p[(i + 1) % n] - p[i];
    		curr -= abs(cross(p[j] - p[i], p[(i + 1) % n] - p[i]));
    		while (dot(p[j], dir) < dot(p[(j + 1) % n], dir)) {
    			int nx = (j + 1) % n;
    			curr += abs(cross(p[j] - p[(i + 1) % n], p[nx] - p[(i + 1) % n]));
    			j = nx;
    		}
    		//cout << i << " " << (i + 1) % n << " " << j << " " << curr << endl;
    		ld t = dot(p[j] - p[(i + 1) % n], dir) / dot(dir, dir);
    		pt q = p[(i + 1) % n] + dir * t;
    		ans = min(ans, abs(cross(p[j] - p[(i + 1) % n], q - p[(i + 1) % n])) - curr);
    	}
    	reverse(all(p));
    }

    cout << fixed;
    cout.precision(20);
    cout << ans / 2 << "\n";
    
}