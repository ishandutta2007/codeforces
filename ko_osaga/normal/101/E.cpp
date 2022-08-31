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
const int oo = 1e9;

int n, m, p;
int x[20005], y[20005];
int dp1[20005], dp2[20005];

string seq;
int ret;

inline int cost(int a, int b){
	return (x[a] + y[b]) % p;
}

void solve(int s, int e, int ps, int pe){
	if(s == e){
		for(int j=ps; j<pe; j++){
			seq.push_back('S');
		}
		return;
	}
	int m = (s+e)/2;
	fill(dp1+ps, dp1+pe+2, 0);
	fill(dp2+ps, dp2+pe+2, 0);
	for(int i=s; i<=m; i++){
		for(int j=ps; j<=pe; j++){
			dp1[j] = max(dp1[j], (j != ps ? dp1[j-1] : 0)) + cost(i, j);
		}
	}
	for(int i=e; i>m; i--){
		for(int j=pe; j>=ps; j--){
			dp2[j] = max(dp2[j], dp2[j+1]) + cost(i, j);
		}
	}
	int tmp = -1, pos = ps;
	for(int i=ps; i<=pe; i++){
		if(dp1[i] + dp2[i] > tmp){
			tmp = dp1[i] + dp2[i];
			pos = i;
		}
	}
	solve(s, m, ps, pos);
	seq.push_back('C');
	solve(m+1, e, pos, pe);
}

int main(){
	scanf("%d %d %d",&n,&m,&p);
	for(int i=0; i<n; i++) scanf("%d",&x[i]);
	for(int i=0; i<m; i++) scanf("%d",&y[i]);
	int ret = 0;
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			dp2[j] = max(dp2[j], dp2[j+1]) + cost(i, j);
		}
	}
	printf("%d\n",dp2[0]);
	solve(0, n-1, 0, m-1);
	puts(seq.c_str());
}