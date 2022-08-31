#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

pi a, b, t;
int n;
pi c[100005];

double dist(pi a, pi b){
	return hypot(b.first - a.first, b.second - a.second);
}

double go(pi a){
	double ret = 2e9, sum = 0;
	for(int i=0; i<n; i++){
		sum += dist(t, c[i]) * 2;
		ret = min(ret, dist(a, c[i]) - dist(t, c[i]));
	}
	return ret + sum;
}

double go2(pi a, pi b){
	double l[100005], r[100005];
	double sum = 0;
	for(int i=0; i<n; i++){
		l[i] = dist(a, c[i]) - dist(t, c[i]);
		r[i] = dist(b, c[i]) - dist(t, c[i]);
		sum += dist(t, c[i]) * 2;
	}
	for(int i=1; i<n; i++){
		l[i] = min(l[i], l[i-1]);
		r[n-i-1] = min(r[n-i-1], r[n-i]);
	}
	double ret = 2e9;
	for(int i=0; i<n-1; i++){
		ret = min(ret, l[i] + r[i+1]);
	}
	return ret + sum;
}

int main(){
	cin >> a.first >> a.second >> b.first >> b.second >> t.first >> t.second;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d %d",&c[i].first, &c[i].second);
	}
	double ret = min(go(a), go(b));
	ret = min(ret, go2(a, b));
	ret = min(ret, go2(b, a));
	printf("%.10f", ret);
}