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

int dp[100005], par[100005];

int n, v[100005], c[100005], l[100005], r[100005];
map<pi, pi> s;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> v[i] >> c[i] >> l[i] >> r[i];
	}
	for(int i=1; i<=n; i++){
		dp[i] = -1e9;
		auto t = s.lower_bound(pi(l[i], c[i] + r[i]));
		if(t != s.end() && t->first == pi(l[i], c[i] + r[i])){
			tie(dp[i], par[i]) = t->second;
			dp[i] += v[i];
		}
		else if(l[i] == 0){
			dp[i] = v[i];
		}
		pi key = pi(l[i] + c[i], r[i]);
		if(s.find(key) != s.end()){
			s[key] = max(s[key], pi(dp[i], i));
		}
		else{
			s[key] = pi(dp[i], i);
		}
	}
	lint ret = -1, retp = 0;
	for(int i=1; i<=n; i++){
		if(r[i] == 0){
			if(ret < dp[i]){
				ret = dp[i];
				retp = i;
			}
		}
	}
	int pos = retp;
	vector<int> trace;
	while(pos){
		trace.push_back(pos);
		pos = par[pos];
	}
	printf("%d\n",trace.size());
	sort(trace.begin(), trace.end());
	for(auto &i : trace){
		printf("%d ",i);
	}
}