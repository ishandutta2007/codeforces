#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
typedef pair<int, int> pi;
const int MAXN = 100005;

int n, m;

struct edg{
	int s, e, x;
	bool operator<(const edg &e)const{
		return x< e.x;
	}
};

int sv[MAXN], ev[MAXN], x[MAXN];
int dp[MAXN], val[MAXN];

void solve(int s, int e){
	if(s == e) return;
	int m = (s+e)/2;
	solve(s, m);
	vector<pi> l, r;
	for(int i=s; i<=m; i++) l.push_back(pi(x[i], i));
	for(int i=m+1; i<=e; i++) r.push_back(pi(x[i], i));
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int ptr = 0;
	for(auto &i : r){
		while(ptr < l.size() && l[ptr].first < i.first){
			int idx = l[ptr].second;
			val[ev[idx]] = max(val[ev[idx]], dp[idx] + 1);
			ptr++;
		}
		dp[i.second] = max(dp[i.second], val[sv[i.second]]);
	}
	for(auto &i : l) val[ev[i.second]] = 0;
	solve(m+1, e);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d",&sv[i],&ev[i],&x[i]);
		dp[i] = 1;
	}
	solve(1, m);
	cout << *max_element(dp, dp + m + 1) << endl;
}