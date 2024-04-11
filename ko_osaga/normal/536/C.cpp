#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 200005;
const long double eps = 1e-14;

struct point{
	long double x, y;
	bool operator<(const point &p)const{
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
};

long double ccw(point a, point b, point c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int n;
pi a[MAXN];

int main(){
	cin >> n;
	vector<point> v, w;
	set<pi> s;
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		if(s.find(a[i]) == s.end()){
			v.push_back({(llf)100.0 / a[i].first, (llf)100.0 / a[i].second});
		}
		s.insert(a[i]);
	}
	sort(v.begin(), v.end());
	for(auto &i : v){
		while(w.size() >= 2 && ccw(w[w.size() - 2], w.back(), i) < -eps){
			w.pop_back();
		}
		w.push_back(i);
	}
	s.clear();
	while(w.size() >= 2 && w[w.size()-2].y - eps <= w.back().y) w.pop_back();
	for(auto &i : w){
		double t1 = 100.0 / i.x;
		double t2 = 100.0 / i.y;
		s.insert(pi((int)round(t1), (int)round(t2)));
	}
	for(int i=0; i<n; i++){
		if(s.find(a[i]) != s.end()) printf("%d ", i+1);
	}
}