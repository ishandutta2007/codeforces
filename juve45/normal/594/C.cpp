#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<endl;}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define EPS 1e-9
const double PI = acos(-1);

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << '\n';
	return out;
}

struct point{
	long long x, y;
	
	point() {	}
	point(const point &a) {x = a.x, y = a.y;}
	point(long long _x, long long _y) { x = _x; y = _y; }

	point operator-(point a) {return point(x - a.x, y - a.y);}
	point operator+(point a) {return point(x + a.x, y + a.y);}

};

ostream& operator<<(ostream& out, point p) { return out << '(' << p.x << ' ' << p.y << ')'; }

long double dist(point a, point b)
{
	long double X = a.x - b.x;
	long double Y = a.y - b.y;
	return sqrt(X * X + Y * Y);
}

istream& operator>>(istream& in, point &p) { return in >> p.x >> p.y; }

long double area(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

const long long N = 100100;

point p1, p2, p[N];
long long n, k, use[N];

vector <pair<long long, long long> > v[5];

long long lg(long long a) {
	if(a % 2 == 1) a++;
	a /= 2;
	return max(1LL, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++) {
		cin >> p1 >> p2;
		p[i] = p1 + p2;
	}

	// dbg_v(p, n + 1);
	for(long long i = 1; i <= n; i++) {
		v[0].push_back({p[i].x, i});
		v[1].push_back({p[i].x, i});
	}

	for(long long i = 1; i <= n; i++) {
		v[2].push_back({p[i].y, i});
		v[3].push_back({p[i].y, i});
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end(), greater<pair<long long, long long> >());
	sort(v[2].begin(), v[2].end());
	sort(v[3].begin(), v[3].end(), greater<pair<long long, long long> >());

	// 0, 1, 2, 3;
	// L, R, U, D
	long long ans = 1e18 + 100;
	for(long long i = 0; i < (1 << (2 * k)); i++) {
		long long order[12], msk = i, used[12];
		for(long long j = 1; j <= k; j++) {
			order[j] = msk % 4;
			msk /= 4;
		}

		long long d[] = {v[0][0].st, v[1][0].st, v[2][0].st, v[3][0].st};

		for(long long j = 1; j <= k; j++) {
			long long p = order[j], ind = 0;

			while(use[v[order[j]][ind].nd]) ind++;

			use[v[p][ind].nd] = 1;
			used[j] = v[p][ind].nd;
		}
		for(int j = 0; j < 4; j++) {
			int ind = 0;
			while(use[v[j][ind].nd]) ind++;
			d[j] = v[j][ind].st;
		}
		// if(d[1] == 4)
		// dbg_v(d, 4);

		ans = min(ans, lg(d[1] - d[0]) * lg(d[3] - d[2]));

		for(long long j = 1; j <= k; j++)
			use[used[j]] = 0;
	}	
	cout << ans << '\n';
}