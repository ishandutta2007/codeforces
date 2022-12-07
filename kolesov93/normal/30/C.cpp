#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <memory.h>
using namespace std;
struct cell {
	long long x,y,t;
	double p;
	
	bool operator <(const cell& A) const {
		return t < A.t;
	}
} a[1111];
int n;
double f[1111];

long long sq2(long long x) {
	return x*x;
}

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
	sort(a,a+n);
	
	double ans = 0;
	for (int i=0;i<n;i++) {
		f[i] = a[i].p;
		for (int j=0;j<i;j++) 
			if (sq2(a[i].x-a[j].x) + sq2(a[i].y-a[j].y) <= sq2(a[i].t-a[j].t)) f[i] = max(f[i],f[j]+a[i].p);
		ans = max(ans,f[i]);
	}
	
	cout.precision(10);
	cout << fixed << ans << endl;
	
	return 0;
}