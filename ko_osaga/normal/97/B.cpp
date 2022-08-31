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
pi a[10005];
vector<pi> v;

void solve(int s, int e){
	if(s == e){
		v.push_back(a[s]);
		return;
	}	
	int m = (s+e)/2;
	solve(s, m);
	solve(m+1, e);
	for(int i=s; i<=e; i++){
		v.push_back(pi(a[m].first, a[i].second));
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);
	solve(0, n-1);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	printf("%d\n",v.size());
	for(auto &i : v){
		printf("%d %d\n",i.first, i.second);
	}
}