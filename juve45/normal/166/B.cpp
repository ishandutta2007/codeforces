#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

struct point{
	long long x, y;
	
	point() {	}

	point(double _x, double _y) {
		x = _x;
		y = _y;
	}
};


long double area(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

int n, k, x, m;
vector<point> p, hull;
set<pair<long long, long long> > p1, p2;
string s;

bool cmp(point a, point b) {
	if(area(p[0], a, b) == 0)
		return a.x > b.x;
	return area(p[0], a, b) > 0;
}

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v)
		out << e.x << ' ' << e.y << '\n';
	return out;
}

bool check(set<pair<long long, long long> > pol) {
	if(hull.size() != pol.size())
		return 0;
	for(auto pct : hull) {
		if(pol.count({pct.x, pct.y}) == 0)
			return 0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		point pct;
		cin >> pct.x >> pct.y; 
		p.push_back(pct);
		p1.insert({pct.x, pct.y});
		if(p[0].x > pct.x || p[0].x == pct.x && p[0].y < pct.y)
			swap(p[0], p[p.size() - 1]);
	}	
    cin >> m;
	for(int i = 1; i <= m; i++) {
		point pct;
		cin >> pct.x >> pct.y; 
		p.push_back(pct);
		if(p1.count({pct.x, pct.y})) {
			cout << "NO\n";
			return 0;
		}
		p2.insert({pct.x, pct.y});
		if(p[0].x > pct.x || p[0].x == pct.x && p[0].y < pct.y)
			swap(p[0], p[p.size() - 1]);
	}	

	sort(p.begin() + 1, p.end(), cmp);

	hull.push_back(p[0]);
	hull.push_back(p[1]);

	int ii = 2;
	while(area(hull[hull.size() - 2], hull[hull.size() - 1], p[ii]) == 0) {
		hull.push_back(p[ii]);
		ii++;
	}

	//dbg(ii);
	for(int i = ii; i < p.size(); i++) {
		// cout << p[i].x << ' ' << p[i].y << endl;
		// cout << hull.back().x << ' ' << hull.back().y << endl;
		// cout << hull[hull.size() - 2].x << ' ' << hull[hull.size() - 2].y << endl;
		while(hull.size() > ii && area(hull[hull.size() - 2], hull[hull.size() - 1], p[i]) < 0) {
			hull.pop_back();
		}
		hull.push_back(p[i]);
	}

	if(check(p1) || check(p2))
		cout << "YES\n";
	else cout << "NO\n";

//	cout << hull;
}