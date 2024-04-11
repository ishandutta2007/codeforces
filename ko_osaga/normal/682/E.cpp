#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

lint dist(pi a, pi b){
	int dx = b.first - a.first;
	int dy = b.second - a.second;
	return 1ll * dx * dx + 1ll * dy * dy;
}

pi a[5005];
int n;
vector<pi> hull;

lint mxarea = 0;
int r1, r2, r3;

void solve(){
	for(int i=0; i+2<hull.size(); i++){
		int p2 = i+1, p3 = i+2;
		while(p2 + 1 < hull.size()){
			p3 = max(p3, p2 + 1);
			while(p3 + 1 < hull.size() &&
				ccw(hull[i], hull[p2], hull[p3]) < ccw(hull[i], hull[p2], hull[p3+1])){
				p3++;
			}
			if(mxarea < ccw(hull[i], hull[p2], hull[p3])){
				mxarea = ccw(hull[i], hull[p2], hull[p3]);
				tie(r1, r2, r3) = make_tuple(i, p2, p3);
			}
			p2++;
		}
	}
	int x1 = hull[r1].first + hull[r2].first - hull[r3].first;
	int x2 = hull[r2].first + hull[r3].first - hull[r1].first;
	int x3 = hull[r3].first + hull[r1].first - hull[r2].first;
	int y1 = hull[r1].second + hull[r2].second - hull[r3].second;
	int y2 = hull[r2].second + hull[r3].second - hull[r1].second;
	int y3 = hull[r3].second + hull[r1].second - hull[r2].second;
	printf("%d %d\n%d %d\n%d %d",x1, y1, x2, y2, x3, y3);
}

int main(){
	lint x;
	cin >> n >> x;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
	}
	swap(a[0], *min_element(a, a+n));
	sort(a+1, a+n, [&](const pi &aa, const pi &bb){
		lint t = ccw(a[0], aa, bb);
		if(t != 0) return t > 0;
		return dist(a[0], aa) < dist(a[0], bb);
	});
	for(int i=0; i<n; i++){
		while(hull.size() >= 2 && ccw(hull[hull.size()-2], hull.back(), a[i]) <= 0){
			hull.pop_back();
		}
		hull.push_back(a[i]);
	}
	solve();
}