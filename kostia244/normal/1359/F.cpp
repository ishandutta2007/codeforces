#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const double E = 1e-9;
double get(array<double, 3> L, double x, double y) {
	return L[0]*x+L[1]*y+L[2];
}
array<double, 3> line(array<double, 4> a) {
	if(abs(a[0]-a[2])<E)
		return {1, 0, a[1]};
	double B = -(a[0]-a[2])/(a[1]-a[3]);
	return {1, B, -get({1, B, 0}, a[0], a[1])};
}
bool check2(array<double, 3> L, array<double, 4> s) {
	return abs(get(L, s[0], s[1])) < E || abs(get(L, s[2], s[3])) < E ||
		(get(L, s[0], s[1])<0)!=(get(L, s[2], s[3])<0);
}
bool check(double a, double b, double c, double d) {
	if(b < a) swap(a, b);
	if(d < c) swap(c, d);
	return min(b, d)-max(a, c) > -E;
}
bool intersect(array<double, 4> a, array<double, 4> b) {
	// cout << "ck"<<endl;
	// cout << "CHECK ";
	// for(auto i : a) cout << i << " "; cout << " : ";
	// for(auto i : b) cout << i << " " ; cout << endl;
	if(!(check(a[0], a[2], b[0], b[2]) && check(a[1], a[3], b[1], b[3])))
		return 0;
	// if(check2(line(a), b) && check2(line(b), a)) {
		// for(auto i : line(a)) cout << i << " "; cout << endl;
		// for(auto i : line(b)) cout << i << " "; cout << endl;
		// exit(0);
	// }
	return check2(line(a), b) && check2(line(b), a);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	auto check = [&](vector<array<double, 4>> seg) {
		int n = seg.size();
		for(auto &[x1, y1, x2, y2] : seg) {
			if(x1 > x2 || (x1 == x2 && y1 > y2))
				swap(x1, x2), swap(y1, y2);
			
		}
		vector<array<double, 3>> events;
		for(int i = 0; i < n; i++) {
			events.push_back({seg[i][0], seg[i][1], i+1});
			events.push_back({seg[i][2], seg[i][3], -i});
		}
		sort(all(events));
		auto get = [&](int i, double p) -> double {
			if(seg[i][2] == seg[i][0]) return 69;
			return seg[i][1] + (p-seg[i][0]) * (seg[i][3]-seg[i][1])/(seg[i][2]-seg[i][0]);
		};
		auto cmp = [&](int i, int j) {//comparator is valid till segments intersect, but when they do we stop the program
			double p = max(seg[i][0], seg[j][0]);
			double x = get(i, p);
			double y = get(j, p);//seg[j][1] + (p-seg[j][0]) * (seg[j][3]-seg[j][1])/(seg[j][2]-seg[j][0]);
			if(abs(x-y) < E)
				return i < j;
			return x<y;
		};
		set<int, decltype(cmp)> hv(cmp);
		vector<decltype(hv.begin())> it(n);
		for(auto [x, y, ID] : events) {
			int id = round(ID);
			if(id > 0) {id--;
				// cout << x << " + " << id << endl;
				it[id] = hv.insert(id).first;	
				auto L = prev(it[id]), R = next(it[id]);
				if(it[id] != hv.begin() && intersect(seg[*L], seg[id])) {
					return 1;
				}
				if(R != hv.end() && intersect(seg[*R], seg[id])) {
					return 1;
				}
			} else {id *= -1;
				// cout << x << " - " << id << endl;
				auto L = prev(it[id]), R = next(it[id]);
				
				if(it[id] != hv.begin() && R != hv.end() && intersect(seg[*L], seg[*R])) {
					return 1;
				}
				hv.erase(it[id]);
			}
			// cout << x << " : ";
			// for(auto [y, id] : hv) cout << id << " "; cout << "z" << endl;
		}
		return 0;
	};
	int n;
	cin >> n;
	vector<array<int, 5>> points(n);
	for(auto &i : points)
		for(int j = 0; j < 5; j++)
			cin >> i[j];
	double l = 0, r= 1e10;
	int ok = 0;
	for(int it = 0; it < 100; it++) {
		double m = (r+l)/2;
		vector<array<double, 4>> segs;
		for(int i = 0; i < n; i++) {
			double d = double(points[i][4])/hypot(points[i][2], points[i][3]);
			double x2 = points[i][0] + m*double(points[i][2])*d;
			double y2 = points[i][1] + m*double(points[i][3])*d;
			// cout << "(" << points[i][0] << ", " << points[i][1] << ")" << endl;
			// cout << "(" << x2 << ", " << y2 << ")" << endl;
			segs.push_back({points[i][0], points[i][1], x2, y2});
		}
		if(check(segs))
			ok = 1, r = m;
		else 
			l = m;
	}
	cout << fixed << setprecision(10);
	if(!ok)
		cout << "No show :(";
	else
		cout << r << '\n';
}//2 3 -6.3205 -2.547 -2 -2 -3.78885 1.57771