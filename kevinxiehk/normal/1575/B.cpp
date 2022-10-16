#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define vi vector<int>
#define vl vector<ll int>
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define DEBUG fprintf(stderr, "Running on Line %d in Function %s\n", __LINE__, __FUNCTION__)
#pragma GCC optimize("Ofast")
using namespace std;
void yes() {
    cout << "YES\n";
    return;
}
void no() {
    cout << "NO\n";
    return;
}
template <class T>
void out(T temp) {
    cout << temp << endl;
    return;
}
void out(double temp) {
    cout << setprecision(7) << fixed << temp << endl;
    return;
}
void out(long double temp) {
    cout << setprecision(7) << fixed << temp << endl;
    return;
}
// global variables
struct pt {
	ld x, y;
	ld deg;
};
const ld PI = 3.14159265358979323846, ep = 1e-7;
void init() {
    // initialize
    
}
ld dist(ld a, ld b) {
	return sqrt(a * a + b * b);
}
ld find_deg(ld x, ld y) {
	if (x == 0 && y == 0) { // origin
		return -1;
	}
	if (x > 0 && y == 0) { // 0 deg
		return 0;
	} if (x > 0 && y > 0) { // quadrant 1
		return atan2(abs(y), abs(x)) / PI * 180;
	} else if (x == 0 && y > 0) { // 90 deg
		return 90;
	} else if (x < 0 && y > 0) { // quadrant 2
		return 90 + atan2(abs(x), abs(y)) / PI * 180;
	} else if (x < 0 && y == 0) { // 180 deg
		return 180;
	} else if (x < 0 && y < 0) { // quadrant 3
		return 180 + atan2(abs(y), abs(x)) / PI * 180;
	} else if (x == 0 && y < 0) { // 270 deg
		return 270;
	} else if (x > 0 && y < 0) { // quadrant 4
		return 270 + atan2(abs(x), abs(y)) / PI * 180;
	} else {
		cout << "GO DEBUG HAHAHAHAHAHAHAHA\n";
	}
	return -2;
}
void solve(int case_no) {
	// implementation
	// wow G9 math be like
	int n, k;
	cin >> n >> k;
	vector<pt> v;
	for (int i = 0; i < n; i++) {
		pt cur;
		cin >> cur.x >> cur.y;
		cur.deg = find_deg(cur.x, cur.y);
		if (cur.deg == -2) {
			cout << "wrong smh\n";
			return;
		} else if (cur.deg == -1) {
			k--;
		} else {
			v.pb(cur);
		}
	}
	if (k <= 0) return out("0.00000000");
	n = v.size();
	//
	cout << setprecision(8) << fixed;
//	cout << "DEBUGGING:\n";
//	for (int i = 0; i < n; i++) {
//		pt cur = v[i];
//		cout << cur.x << ' ' << cur.y << ' ' << cur.deg << endl;
//	}
	//
	ld lb = 0, rb = 2e5;
	int turns = 32;
	while (turns--) {
		ld mid = (lb + rb) / 2;
		priority_queue<pair<ld, bool>, vector<pair<ld, bool> >, greater<pair<ld, bool> > > pq;
		for (int i = 0; i < n; i++) {
			if (dist(v[i].x, v[i].y) > 2 * mid) continue;
			pt cen; // center of circle
			if (true) {
				ld s = (2 * mid + dist(v[i].x, v[i].y)) / 2;
				ld area = sqrt(s * (s - mid) * (s - mid) * (s - dist(v[i].x, v[i].y))); // heron
				ld midpt_dist = area * 2 / dist(v[i].x, v[i].y);
				pt midpt;
				midpt.x = v[i].x / 2.0;
				midpt.y = v[i].y / 2.0;
				if (v[i].x == 0) {
					cen.x = midpt.x + (area * 2 / dist(v[i].x, v[i].y));
					cen.y = midpt.y;
				} else if (v[i].y == 0) {
					cen.x = midpt.x;
					cen.y = midpt.y + (area * 2 / dist(v[i].x, v[i].y));
				} else {
					ld slope = v[i].y * 1.0 / v[i].x;
					slope = -1.0 / slope;
					// (m^2+1)k^2 = dist^2
					ld deltax = sqrt((midpt_dist * midpt_dist) / (slope * slope + 1));
					if (slope > 0) {
						cen.x = midpt.x + deltax;
						cen.y = midpt.y + (slope * deltax);
					} else {
						cen.x = midpt.x + deltax;
						cen.y = midpt.y + (slope * deltax);
					}
				}
				cen.deg = find_deg(cen.x, cen.y);
				pt cen2;
				cen2.x = (midpt.x - (cen.x - midpt.x));
				cen2.y = (midpt.y - (cen.y - midpt.y));
				cen2.deg = find_deg(cen2.x, cen2.y);
				if (cen.deg > cen2.deg) swap(cen, cen2);
				if (cen2.deg - cen.deg > 180) {
					cen.deg += 360;
					swap(cen, cen2);
				}
//				cout << "DEBUG  " << v[i].x << ' ' << v[i].y << ' ' << cen.deg << ' ' << cen2.deg << endl;
				pq.push({cen.deg, true});
				pq.push({cen.deg + 360, true});
				pq.push({cen2.deg, false});
				pq.push({cen2.deg + 360, false});
			}
		}
		ld prev = -10000;
		int cnt = 0, best = 0;
//		cout << "mid = " << mid << endl;
		while (!pq.empty()) {
			pair<ld, bool> cur = pq.top();
			pq.pop();
//			cout << cur.ff << ' ' << cur.ss << endl;
			if (abs(cur.ff - prev) > ep) {
				best = max(best, cnt);
			}
			prev = cur.ff;
			if (cur.ss) cnt++;
			else cnt--;
		}
		if (best >= k) rb = mid;
		else lb = mid;
	}
	cout << lb << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    init();
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
/*

*/