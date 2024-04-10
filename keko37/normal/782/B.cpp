#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

typedef long long llint;

const int MAXN = 60005;
const llint INF = 2000000005000000005LL;

int n;
double ofs = 100000000;
double l[MAXN];
double v[MAXN];

bool f (double t) {
	double lef=-INF, rig=INF;
	for (int i=0; i<n; i++) {
		lef=max(lef, l[i]-v[i]*t);
		rig=min(rig, l[i]+v[i]*t);
	}
	return lef<=rig;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	llint low=0, high=100000000000000000LL, mid;
	while (low<high) {
		mid=(low+high)/2;
		if (f(mid/ofs)) {
			high=mid;
		} else {
			low=mid+1;
		}
	}
	printf("%.9f", low/ofs);
	return 0;
}