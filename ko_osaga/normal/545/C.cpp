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
typedef pair<double, int> pi;

int n;
vector<pi> v;
int a[100005], b[100005];
set<int> s;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%d %d",&a[i], &b[i]);
	}
	for(int i=1; i<=n; i++){
		int q = upper_bound(a+1, a+n+1, a[i] + b[i]) - upper_bound(a+1, a+n+1, a[i]);
		if(q == 0){
			v.emplace_back(a[i], a[i] + b[i]);
		}
		q = lower_bound(a+1, a+n+1, a[i]) - lower_bound(a+1, a+n+1, a[i] - b[i]);
		if(q == 0){
			v.emplace_back(a[i] - b[i], a[i]);
		}
	}
	sort(v.begin(), v.end(), [&](const pi &a, const pi &b){
		return a.second < b.second;
	});
	int ep = -2e9, cnt = 0;
	for(auto &i : v){
		if(ep < i.first){
			ep = i.second;
			cnt++;
		}
	}
	cout << cnt;
}