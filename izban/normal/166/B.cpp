#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=101000;

struct point {
	ll x,y,o;
	bool operator<(const point &a) {
		return x<a.x || x==a.x && y<a.y;
	}
};


int n,m;
vector<point> a;

bool cw(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<=0;
}

bool ccw(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>=0;
}

void convex_hull(vector<point> &a) {
	if (a.size()==1) return;
	sort(a.begin(),a.end());
	point p1=a.front(),p2=a.back();
	vector<point> up,down;
	up.push_back(p1);
	down.push_back(p1);
	for (int i=1; i<a.size(); i++) {
		if (i==a.size() || cw(p1,a[i],p2)) {
			while (up.size()>=2 && !cw(up[up.size()-2],up[up.size()-1],a[i])) up.pop_back();
			up.push_back(a[i]);
		}
		if (i==a.size() || ccw(p1,a[i],p2)) {
			while (down.size()>=2 && !ccw(down[down.size()-2],down[down.size()-1],a[i])) down.pop_back();
			down.push_back(a[i]);
		}
	}
	a.clear();
	for (int i=0; i<up.size(); i++) 
		a.push_back(up[i]);
	for (int i=down.size()-2; i; i--) 
		a.push_back(down[i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) {
		point b;
		cin >> b.x >> b.y;
		b.o=0;
		a.push_back(b);
	}
	cin >> m;
	for (int i=0; i<m; i++) {
		point b;
		cin >> b.x >> b.y;
		b.o=1;
		a.push_back(b);
	}

	convex_hull(a);

	for (int i=0; i<a.size(); i++)
		if (a[i].o==1) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}