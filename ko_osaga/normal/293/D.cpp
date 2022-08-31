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
typedef pair<int, int> pi;

int n;
pi a[100005];

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

int cnt[2000005], low[2000005], high[2000005];
lint tot = 0;

llf solve(){
	memset(low, 0x3f, sizeof(low));
	memset(high, 0, sizeof(high));
	lint tmp = 0;
	for(int i=0; i<n; i++){
		bool swp = 0;
		if(a[i] > a[i+1]){
			swp = 1;
			swap(a[i], a[i+1]);
		}
		if(a[i].first == a[i+1].first){
			low[a[i].first] = a[i].second;
			high[a[i].first] = a[i+1].second;
		}
		else{
			for(int j=a[i].first; j<=a[i+1].first; j++){
				double t = 1.0 * (j - a[i].first) / (a[i+1].first - a[i].first);
				double p = t * (a[i+1].second - a[i].second) + a[i].second;
				low[j] = min(low[j], (int)ceil(p - 1e-10));
				high[j] = max(high[j], (int)floor(p + 1e-10));
			}
		}
		if(swp) swap(a[i], a[i+1]);
	}
	llf ret = 0; 
	tot = 0;
	for(int i=0; i<=2000000; i++){
		cnt[i] = max(0, high[i] - low[i] + 1);
		tot += cnt[i];
	}
	llf t0 = 0, t1 = 0, t2 = 0;
	for(int j=0; j<=2000000; j++){
		t0 += 1.0 * cnt[j] * j * j;
		t1 += -2.0 * cnt[j] * j;
		t2 += 1.0 * cnt[j];
	}
	for(int i=0; i<=2000000; i++){
		ret += 1.0 * cnt[i] * t0;
		ret += 1.0 * cnt[i] * i * t1;
		ret += 1.0 * cnt[i] * i * i * t2;
	}
	ret /= 2;
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
		a[i].first += 1000000;
		a[i].second += 1000000;
	}
	a[n] = a[0];
	double ret = solve();
	for(int i=0; i<=n; i++){
		swap(a[i].first, a[i].second);
	}
	ret += solve();
	ret /= tot;
	ret /= tot - 1;
	printf("%.10f",ret);
}