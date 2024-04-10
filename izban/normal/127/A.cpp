#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))

double ans=0,x[2000],y[2000];
int n,k;

double dist(int i, int j) {
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		if (i) ans+=dist(i,i-1);
	}
	ans=ans*k/50;
	printf("%.11lf",ans);
	return 0;
}