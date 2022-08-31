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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

int n, a[200005];
double b[200005];

double solve(){
	double ret = -1e9, cur = 0;
	for(int i=0; i<n; i++){
		cur += b[i];
		ret = max(ret, cur);
		if(cur < 0) cur = 0;
	}
	return ret;
}

double trial(double x){
	for(int i=0; i<n; i++){
		b[i] = a[i] - x;
	}
	double ret = solve();
	for(int i=0; i<n; i++){
		b[i] = x - a[i];
	}
	return fabs(max(ret, solve()));
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	double s = -1e5, e = 1e5;
	for(int i=0; i<100; i++){
		double m1 = (s*2+e)/3;
		double m2 = (s+2*e)/3;
		if(trial(m1) < trial(m2)) e = m2;
		else s = m1;
	}
	printf("%.10f",trial(s));
}