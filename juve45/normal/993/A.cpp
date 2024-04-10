#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 123;
int n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


struct point{
	int x, y;
	
	point() {	}
	point(int a, int b) {x =a, y = b;	}
	point(const point &a) {x = a.x, y = a.y;}
	
	point operator-(point &a) {return point(x - a.x, y - a.y);}
	point operator+(point &a) {return point(x + a.x, y + a.y);}
	
};


long long area(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

istream& operator>>(istream& in, point &p) { return in >> p.x >> p.y; }


bool intersect(point ap, point bp, point aq, point bq)
{
if( area(ap, bp, aq) * area(ap, bp, bq) > 0 )
    return false;
if( area(aq, bq, ap) * area(aq, bq, bp) > 0 )
    return false;
if( area(aq, bq, ap) * area(aq, bq, bp) == 0  && area(ap, bp, aq) * area(ap, bp, bq) == 0)
    if( max(aq.x, bq.x) < min(ap.x, bp.x) || min(aq.x, bq.x) > max(ap.x, bp.x))
        return false;
return true;
}

point p1[5], p2[5];


int grid[300][300];

bool check2() {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(intersect(p1[i], p1[(i + 1) % 4], p2[j], p2[(j + 1) % 4]))
				return true;
		}
	}


	// point centru = p2[0] + p2[1] + p2[2] + p2[3];
	// centru.x = centru.x / 4;
	// centru.y = centru.y / 4;

	// int a1 = area(p1[0], p1[1], p1[2]) * 2;
	// int a2 = area(p2[0], p2[1], p2[2]) * 2;
	// int i = 4;
	

	// for(int i = 0; i < 4; i++) {
	// 	maxx = max(maxx, p1[i].x);
	// 	maxy = max(maxy, p1[i].y);
	// 	minx = min(minx, p1[i].x);
	// 	miny = min(miny, p1[i].y);
	// }



	// for(int i = -100; i <= 100; i++) {
	// 	for(int j = -100; j <= 100; j++)
	// 		if(maxx >= i && minx <= i && maxy >= j && miny <= j)
	// 			grid[i + 100][j + 100] = 1;
	// }

	// for(int i = 0; i < 4; i++) {
	// 	if(grid[][])
	// }
	// grid[][]

	// in centru
	return false;
}

bool check() {
	int a1 = abs(area(p1[0], p1[1], p1[2]) * 2);
	int a2 = abs(area(p2[0], p2[1], p2[2]) * 2);
	// dbg(a1);
	// dbg(a2);
	for(int i = 0; i < 4; i++) {
		int are = 0;
		for(int j = 0; j < 4; j++)
			are += abs(area(p1[i], p2[j], p2[(j + 1) % 4]));
		if(are == a2)
			return true;

		are = 0;
		for(int j = 0; j < 4; j++)
			are += abs(area(p2[i], p1[j], p1[(j + 1) % 4]));
		if(are == a1)
			return true;
	}
	return false;

}

int main() {
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 4; i++) cin >> p1[i];
	for(int i = 0; i < 4; i++) cin >> p2[i];

	if(check() || check2()) cout << "YES\n";
	else cout << "NO\n";

}