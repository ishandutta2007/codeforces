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
typedef pair<lint, lint> pi;

int n;
pi a[100005];

lint pymax[100005], pymin[100005];
lint symax[100005], symin[100005];

bool trial(lint x){
	for(int i=0; i<n; i++){
		symax[i] = pymax[i] = a[i].second - x;
		symin[i] = pymin[i] = a[i].second + x;
	}
	for(int i=1; i<n; i++){
		pymax[i] = max(pymax[i], pymax[i-1]);
		pymin[i] = min(pymin[i], pymin[i-1]);
	}
	for(int i=n-2; i>=0; i--){
		symax[i] = max(symax[i], symax[i+1]);
		symin[i] = min(symin[i], symin[i+1]);
	}
	int e = 0;
	for(int i=0; i<n; i++){
		while(e < n && a[e].first <= a[i].first + x * 2){
			e++;
		}
		lint maxv = -1e18, minv = 1e18;
		if(i) maxv = max(maxv, pymax[i-1]), minv = min(minv, pymin[i-1]);
		if(e < n) maxv = max(maxv, symax[e]), minv = min(minv, symin[e]);
		if(maxv <= minv){
			return 1;
		}
	}
	return 0;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int x, y; scanf("%d %d",&x,&y);
		a[i] = pi(x+y, x-y);
		a[i].first *= 2ll;
		a[i].second *= 2ll;
	}
	sort(a, a+n);
	lint s = 0, e = 1e10;
	while(s != e){
		lint m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m+1;
	}
	printf("%.10f",s * 0.5);
}