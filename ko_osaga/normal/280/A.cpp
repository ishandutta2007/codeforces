#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<llf, llf> pi;
const llf eps = 1e-6;
 
struct halfplane{
    llf a, b, c; 
};
 
llf faabs(llf a){
	return a< 0 ? -a : a;
}

halfplane draw(llf sx, llf sy, llf ex, llf ey, llf x, llf y){
    halfplane p = {1.0 * (ey-sy), 1.0 * (sx-ex), -1};
    p.c = -p.a * sx -p.b * sy;
    if(p.a * x + p.b * y + p.c < 0){
        p.a = -p.a;
        p.b = -p.b;
        p.c = -p.c;
    }
    return p;
}
 
llf ccw(pi a, pi b, pi c){
    llf dx1 = b.first - a.first;
    llf dy1 = b.second - a.second;
    llf dx2 = c.first - a.first;
    llf dy2 = c.second - a.second;
    return dx1 * dy2 - dy1 * dx2;
}
 
pi cross(halfplane a, halfplane b){
    llf det = a.a * b.b - a.b * b.a;
    llf d1 = a.b * b.c - a.c * b.b;
    llf d2 = a.c * b.a - a.a * b.c;
    if(faabs(det) < eps) return pi(-1e9, -1e9);
    return pi(d1 / det, d2 / det);
}
 

llf dist(pi a, pi b){
	return hypot(b.first - a.first, b.second - a.second);
}

llf solve(vector<halfplane> &v){
    vector<pi> pnts, calc;
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            pi t = cross(v[i], v[j]);
            if(t.first < -1e8) continue;
            bool bad = 0;
            for(int k=0; k<v.size(); k++){
                if(t.first * v[k].a + t.second * v[k].b + v[k].c < -eps){
                    bad = 1;
                    break;
                }
            }
            if(!bad) pnts.push_back(t);
        }
    }
    if(pnts.empty()) return 0;
    for(auto &i : pnts){
    	bool bad = 0;
    	for(auto &j : calc){
    		if(dist(i, j) < eps){
    			bad = 1;
    			break;
    		}
    	}
    	if(!bad) calc.push_back(i);
    }
    swap(calc[0], *min_element(calc.begin(), calc.end()));
    sort(calc.begin() + 1, calc.end(), [&](const pi &a, const pi &b){
    	llf tmp = ccw(calc[0], a, b);
    	if(faabs(tmp) < eps) return dist(calc[0], a) < dist(calc[0], b);
        return tmp > 0;
    });
    llf ret = 0;
    for(int i=1; i<calc.size()-1; i++){
        ret += ccw(calc[0], calc[i], calc[i+1]);
    }
    return ret;
}
 
int main(){
	int w, h, ang;
	cin >> w >> h >> ang;
	vector<halfplane> v;
	pi a[4] = {{1.0 * w, 1.0 * h}, {1.0 * w, -1.0 * h}, {-1.0 * w, -1.0 * h}, {-1.0 * w, 1.0 * h}};
	for(int i=0; i<4; i++){
		pi p1 = a[i], p2 = a[(i+1)&3];
		v.push_back(draw(p1.first, p1.second, p2.first, p2.second, 0.0, 0.0));
	}
	llf rad = (acos(-1) * ang) / 180.0;
	for(int i=0; i<4; i++){
		a[i] = pi(a[i].first * cos(rad) - a[i].second * sin(rad), a[i].first * sin(rad) + a[i].second * cos(rad));
	}
	for(int i=0; i<4; i++){
		pi p1 = a[i], p2 = a[(i+1)&3];
		v.push_back(draw(p1.first, p1.second, p2.first, p2.second, 0.0, 0.0));
	}
	printf("%.10f",(double)solve(v) * 0.125);
}