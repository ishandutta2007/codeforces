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
typedef pair<llf, int> pi;

int n, k, a[200005];
llf s1[200005], s2[200005];

int s, e;
llf la[200005],lb[200005];
int idx[200005];

void insert(llf p, llf q, int i){ // p is increasing
	la[e] = p;
	lb[e] = q;
	idx[e] = i;
	while(s+1<e && (lb[e-1] - lb[e-2]) * (la[e] - la[e-1]) <= (la[e-2] - la[e-1])* (lb[e-1] - lb[e])){
		la[e-1] = la[e];
		lb[e-1] = lb[e];
		idx[e-1] = idx[e];
		e--;
	}
	e++;
}

pi dp[200005];

pi query(llf x){ // query is increasing
	while(s+1<e && lb[s+1] - lb[s] >= x * (la[s] - la[s+1])) s++;
	return pi(la[s] * x + lb[s], idx[s]);
}

pi trial(double l){
	s = e = 0;
	insert(0, 0, 0);
	for(int j=1; j<=n; j++){
		dp[j] = query(s2[j]);
		dp[j].first = -dp[j].first + l;
		dp[j].second++;
		insert(s1[j], -dp[j].first - s1[j] * s2[j], dp[j].second);
	}
	return dp[n];
}

int main(){
	scanf("%d %d",&n,&k);
	double ans = 0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		s1[i] = s1[i-1] + a[i];
		s2[i] = s2[i-1] + 1.0 / a[i];
		ans += s1[i] / a[i];
	}
	double s = 0, e = 1e18;
	for(int i=0; i<100; i++){
		double m = (s+e)/2;
		if(trial(m).second <= k) e = m;
		else s = m;
	}
	printf("%.20f", (double)trial(s).first - s * k + ans);
}