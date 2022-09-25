#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

const double eps=1e-9;

int vp,vd,t1,f,c,ans;
string s;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> vp >> vd >> t1 >> f >> c;
	if (vp>=vd) {
		cout << 0;
		return 0;
	}
	double t=t1;
	double x=vp*t;
	while (c*1.0-x>eps) {
		t+=x/(vd-vp+0.0);
		double nx=vp*t;
		if (c*1.0-nx>eps) {
			t+=nx/(vd+0.0)+f;
			ans++;
		}
		x=vp*t;
	}
	cout << ans;
	return 0;
}