#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
const double PI = atan2(1, 0) * 2;
const double TAU = atan2(1, 0) * 4;
const int MAXN = 200005;
const int MAXT = 400005;

struct bit{
	int tree[MAXT];
	void add(int x, int v){
		x += 2;
		for(int i=x; i<MAXT; i+=i&-i) tree[i] += v;
	}
	int query(int x){
		x += 2;
		int ret = 0;
		for(int i=x; i; i-=i&-i) ret += tree[i];
		return ret;
	}
	int query(int s, int e){ return query(e) - query(s - 1); }
	void clear(){
		memset(tree, 0, sizeof(tree));
	}
}bit;

struct queryI{
	int pos, s, e, x;
	bool operator<(const queryI &q)const{
		return pos < q.pos;
	}
};

struct pointI{
	int x, y;
	bool operator<(const pointI &p)const{
		return x < p.x;
	}
};

lint solve(vector<queryI> query, vector<pointI> point){
	sort(all(point));
	sort(all(query));
	bit.clear();
	lint ret = 0;
	int j = 0;
	for(auto &i : query){
		while(j < sz(point) && point[j].x <= i.pos){
			bit.add(point[j++].y, +1);
		}
		ret += i.x * bit.query(i.s, i.e);
	}
	return ret;
}

int n;

pair<double, double> pts[MAXN]; // len, atan2
pair<double, double> ranges[MAXN];

lint solve(double dist){
	lint cnt = 0;
	int N = 0;
	for(int i=0; i<n; i++){
		if(pts[i].first <= dist) continue;
		double angRange = acos(dist / pts[i].first);
		double a = pts[i].second - angRange;
		double b = pts[i].second + angRange;
		if (a < 0) a += TAU, b += TAU;
		ranges[N++] = {a, b};
	}
	sort(ranges, ranges + N);
	vector<double> coords;
	for (int i = 0; i < N; i++) {
		ranges[i+N].first = ranges[i].first + TAU;
		ranges[i+N].second = ranges[i].second + TAU;
	}
	for(int i = 0; i < 2 * N; i++){
		coords.push_back(ranges[i].first);
		coords.push_back(ranges[i].second);
	}
	sort(all(coords));
	coords.resize(unique(all(coords)) - coords.begin());
	auto comp = [&](double x){
		int ans = lower_bound(all(coords), x) - coords.begin();
		return ans;
	};
	vector<queryI> query;
	vector<pointI> point;
	for(int i = 0; i < N; i++){
		int s = comp(ranges[i].second);
		int e = comp(ranges[i + N].first);
		query.push_back({e, s, e, +1});
		query.push_back({s-1, s, e, -1});
	}
	for(int i = 0; i < 2*N; i++){
		int s = comp(ranges[i].first);
		int e = comp(ranges[i].second);
		point.push_back({s, e});
	}
	cnt = solve(query, point) / 2;
	query.clear();
	point.clear();
	for(int i = 0; i < N; i++){
		int s = comp(ranges[i].first);
		int e = comp(ranges[i].second);
		query.push_back({e, s, e, +1});
		query.push_back({s-1, s, e, -1});
	}
	for(int i = 0; i < 2*N; i++){
		int s = comp(ranges[i].first);
		int e = comp(ranges[i].second);
		point.push_back({s, e});
	}
	cnt += solve(query, point) - N;
	// cnt : real nonintersecting dudes
	cnt = 1ll * N * (N - 1) / 2 - cnt;
	return 1ll * n * (n - 1) / 2 - cnt;
}

using pi = pair<int, int>;

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

lint dot(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dx2 + 1ll * dy1 * dy2;
}

pair<int, int> a[MAXN];
int main(){
	lint k;
	auto isGood =[&](double x){
		lint ff = solve(x);
		return ff < k;
	};
	scanf("%d %lld",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		lint x, y;
		x = a[i].first;
		y = a[i].second;
		pts[i].first = double(sqrt(x * x + y * y));
		pts[i].second = atan2(y, x);
		if (pts[i].second < 0) pts[i].second += 2 * PI;
	}
	// start dm
/*
	vector<double> v;
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			lint qq = abs(ccw(pi(0, 0), a[i], a[j]));
			lint k = dot(a[i], a[j], a[j]);
			v.push_back(qq / sqrt(k));
		}
	}
	sort(all(v));
*/	
	// end dm
	auto fnfn = [&](){
		double mi = 0, ma = 2e4;
		if (isGood(1)) {
			mi = 1;
			for (int z = 0; z < 30; z++) {
				double md = mi * sqrt(ma / mi);
				if (isGood(md)) {
					mi = md;
				} else {
					ma = md;
				}
			}
		} else {
			ma = min(ma, 1.);
			for (int z = 0; z < 30; z++) {
				double md = mi + (ma - mi) / 2;
				if (isGood(md)) {
					mi = md;
				} else {
					ma = md;
				}
			}
		}
		return mi;
	};
/*
	for(int i=0; i<sz(v); i++){
		k = i + 1;
		double a = v[i];
		double b = fnfn();
		double err = abs(a - b) / max(1.0, abs(b));
		if(err > 1e-8) assert(0);
	}
	*/
	printf("%.69f\n", fnfn());
}