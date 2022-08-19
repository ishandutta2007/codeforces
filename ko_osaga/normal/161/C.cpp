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

bool mid(int s, int x, int e){
	return s <= x && x <= e;
}

int dp[64][64][64][64];

int f(int s, int e, int ps, int pe, int p){
	if(s > e || ps > pe) return 0;
	if(p <= 6 && ~dp[s][e][ps][pe]) return dp[s][e][ps][pe];
	if(p == 0) return 0;
	int m = (1 << (p - 1));
	if(mid(s, m-1, e) && mid(ps, m-1, pe)){
		int ret = max(0, min(pe, e) - max(ps, s) + 1);
		if(!(e <= ps && pe <= s) && !(pe <= s && e <= ps)){
			if(s < ps) swap(s, ps), swap(e, pe);
			ret = max(ret, f(ps, m-2, 0, e-m, p-1));
		}
		if(p <= 6) return dp[s][e][ps][pe] = ret;
		return ret;
	}
	if(mid(s, m-1, e)){
		if(p <= 6) return dp[s][e][ps][pe] = f(ps, pe, s, e, p);
		return f(ps, pe, s, e, p);
	}
	if(mid(ps, m-1, pe)){
		if(p <= 6) return dp[s][e][ps][pe] = max(f(s%m, e%m, ps, m-2, p-1), f(s%m, e%m, 0, pe-m, p-1));
		return max(f(s%m, e%m, ps, m-2, p-1), f(s%m, e%m, 0, pe-m, p-1));
	}
	if(p <= 6) return dp[s][e][ps][pe] = f(s%m, e%m, ps%m, pe%m, p-1);
	return f(s%m, e%m, ps%m, pe%m, p-1);
}

int main(){
	memset(dp, -1, sizeof(dp));
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	l1--, r1--, l2--, r2--;
	cout << f(l1, r1, l2, r2, 30);
}