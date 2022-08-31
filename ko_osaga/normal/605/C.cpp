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
#include <stdio.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, p, q;
pi a[100005];

vector<pi> v1, v2;
llf ret;

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

int main(){
	cin >> n >> p >> q;
	llf ret = 1e19;
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first, &a[i].second);
		ret = min(ret, max((llf) p / a[i].first, (llf) q / a[i].second));
	}
	sort(a, a+n);
	vector<pi> v;
	for(int i=n-1; i>=0; i--){
		while(v.size() >= 2 && ccw(v[v.size()-2], v.back(), a[i]) <= 0){
			v.pop_back();
		}
		v.push_back(a[i]);
	}
	for(int i=0; i+1<v.size(); i++){
		if(ccw(pi(0, 0), v[i], pi(p, q)) > 0 && ccw(pi(0, 0), pi(p, q), v[i+1]) > 0){
			lint a = v[i+1].second - v[i].second;
			lint b = v[i].first - v[i+1].first;
			lint c = (a * v[i].first + b * v[i].second);
			ret = min(ret, (llf) (a * p + b * q) / c);
		}
	}
	printf("%.10f", (double)ret);
}