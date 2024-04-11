#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
const int mod = 1e9 + 7;
const int MAXN = 400005;

const double eps = 1e-8;

typedef pair<int, int> pi;
lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

llf ccw(pair<llf, llf> a, pair<llf, llf> b, pair<llf, llf> c){
	llf dx1 = b.first - a.first;
	llf dy1 = b.second - a.second;
	llf dx2 = c.first - a.first;
	llf dy2 = c.second - a.second;
	return dx1 * dy2 - dy1 * dx2;
}

namespace hpi{
	using pi = pair<long double, long double>;
	bool z(long double x){ return fabs(x) < eps; }
	struct line{
		long double a, b, c;
		bool operator<(const line &l)const{
			bool flag1 = pi(a, b) > pi(0, 0);
			bool flag2 = pi(l.a, l.b) > pi(0, 0);
			if(flag1 != flag2) return flag1 > flag2;
			long double t = ccw(pi(0, 0), pi(a, b), pi(l.a, l.b));
			return z(t) ? c * hypot(l.a, l.b) < l.c * hypot(a, b) : t > 0;
		}
		pi slope(){ return pi(a, b);}
	}; 
	pi cross(line a, line b){
		long double det = a.a * b.b - b.a * a.b;
		return pi((a.c * b.b - a.b * b.c) / det, (a.a * b.c - a.c * b.a) / det);
	}
	bool bad(line a, line b, line c){
		if(ccw(pi(0, 0), a.slope(), b.slope()) <= 0) return false;
		pi crs = cross(a, b);
		return crs.first * c.a + crs.second * c.b >= c.c;
	}
	bool solve(vector<line> v, vector<pi> &solution){ // ax + by <= c;
		sort(v.begin(), v.end());
		deque<line> dq;
		for(auto &i : v){
			if(!dq.empty() && z(ccw(pi(0, 0), dq.back().slope(), i.slope()))) continue;
			while(dq.size() >= 2 && bad(dq[dq.size()-2], dq.back(), i)) dq.pop_back();
			while(dq.size() >= 2 && bad(i, dq[0], dq[1])) dq.pop_front();
			dq.push_back(i);
		}
		while(dq.size() > 2 && bad(dq[dq.size()-2], dq.back(), dq[0])) dq.pop_back();
		while(dq.size() > 2 && bad(dq.back(), dq[0], dq[1])) dq.pop_front();
		vector<pi> tmp;
		for(int i=0; i<dq.size(); i++){
			line cur = dq[i], nxt = dq[(i+1)%dq.size()];
			if(ccw(pi(0, 0), cur.slope(), nxt.slope()) <= eps) return false;
			tmp.push_back(cross(cur, nxt));
		}
		solution = tmp;
		return true;
	}
};

int n;
pi a[MAXN];
int p[MAXN];

int getnxt(int x){
	x++;
	if(x == n) x = 1;
	return x;
}

int getprv(int x){
	x--;
	if(x == 0) x = n-1;
	return x;
}

void solve(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d %d",&a[i].first,&a[i].second);
	sort(a+1, a+n, [&](const pi &p, const pi &q){
		bool p1 = (a[0] < p);
		bool p2 = (a[0] < q);
		if(p1 != p2) return p1 > p2;
		return ccw(a[0], p, q) > 0;
	});
	vector<hpi::line> v;
	v.push_back({1.0, 0, 1000000.0});
	v.push_back({0, 1.0, 1000000.0});
	v.push_back({-1.0, 0, 1000000.0});
	v.push_back({0, -1.0, 1000000.0});
	int nxt = 1;
	for(int i=1; i<n; i++){
		if(ccw(a[0], a[i], a[getnxt(i)]) == 0){
			puts("0");
			return;
		}
		if(nxt == i) nxt = getnxt(nxt);
		while(ccw(a[0], a[i], a[nxt]) > 0) nxt = getnxt(nxt);
		p[i] = nxt;
		if(ccw(a[0], a[i], a[nxt]) == 0 && i != nxt){
			puts("0");
			return;
		}
		if(nxt == i) nxt = getnxt(nxt);
	}
	for(int i=1; i<n; i++){
		int nxt = p[i];
		if(nxt != i){
			assert(ccw(a[0], a[i], a[nxt]) < 0);
			pi p1 = a[i];
			pi p2 = a[nxt];
			lint a = p1.second - p2.second;
			lint b = p2.first - p1.first;
			lint c = a * p1.first + b * p1.second; 
			v.push_back({(llf)a, (llf)b, (llf)c});
		}
		{
			if(ccw(a[0], a[i], a[getnxt(i)]) > 0){
				int nxt = getnxt(i);
				pi p1 = a[i];
				pi p2 = a[nxt];
				lint a = p1.second - p2.second;
				lint b = p2.first - p1.first;
				lint c = a * p1.first + b * p1.second; 
				v.push_back({(llf)-a, (llf)-b, (llf)-c});
			}
		}
		if(getprv(nxt) != i){
			pi p1 = a[i];
			pi p2 = a[getprv(nxt)];
			lint a = p1.second - p2.second;
			lint b = p2.first - p1.first;
			lint c = a * p1.first + b * p1.second; 
			v.push_back({-(llf)a, -(llf)b, -(llf)c});
		}

	}
//	for(auto &i : v) printf("%.10Lf %.10Lf %.10Lf\n", i.a, i.b, i.c);
	vector<pair<llf, llf>> w;
	if(!hpi::solve(v, w)){
		puts("0.0");
	}
	else{
		double ans = 0;
		for(int i=2; i<w.size(); i++) ans += ccw(w[0], w[i-1], w[i]);
		printf("%.10f\n", ans / 2);
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}