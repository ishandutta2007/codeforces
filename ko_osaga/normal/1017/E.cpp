#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

lint dist(pi a, pi b){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	return 1ll * dx1 * dx1 + 1ll * dy1 * dy1;
}

int fail[1000005];

bool rot_same(vector<lint> a, vector<lint> b){
	for(int i=0; i<a.size(); i++) b.push_back(b[i]);
	int p = 0;
	for(int i=1; i<a.size(); i++){
		while(p && a[i] != a[p]) p = fail[p];
		if(a[i] == a[p]) p++;
		fail[i + 1] = p;
	}
	p = 0;
	for(auto &i : b){
		while(p && i != a[p]) p = fail[p];
		if(i == a[p]) p++;
		if(p == a.size()) return true;
	}
	return false;
}

vector<pi> getPoly(int n){
	vector<pi> h;
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		h.emplace_back(x, y);
	}
	swap(h[0], *min_element(h.begin(), h.end()));
	sort(h.begin() + 1, h.end(), [&](const pi &a, const pi &b){
		auto x = ccw(h[0], a, b);
		if(x != 0) return x > 0;
		return dist(h[0], a) < dist(h[0], b);
	});
	vector<pi> poly;
	for(auto &i : h){
		while(poly.size() >= 2 && ccw(poly[poly.size()-2], poly.back(), i) <= 0){
			poly.pop_back();
		}
		poly.push_back(i);
	}
	return poly;
}

int main(){
	int n, m; cin >> n >> m;
	auto p1 = getPoly(n);
	auto p2 = getPoly(m);
	if(p1.size() != p2.size()){
		puts("NO");
		return 0;
	}
	if(p1.size() == 2 && p2.size() == 2){
		lint c1 = dist(p1[0], p1[1]);
		lint c2 = dist(p2[0], p2[1]);
		if(c1 != c2) puts("NO");
		else puts("YES");
		return 0;
	}
	n = p1.size();
	vector<lint> seq1, seq2;
	for(int i=0; i<n; i++){
		seq1.push_back(-dist(p1[i], p1[(i+1)%n]));
		seq1.push_back(ccw(p1[i], p1[(i+1)%n], p1[(i+2)%n]));
		seq2.push_back(-dist(p2[i], p2[(i+1)%n]));
		seq2.push_back(ccw(p2[i], p2[(i+1)%n], p2[(i+2)%n]));
	}
	puts(rot_same(seq1, seq2) ? "YES" : "NO");
}