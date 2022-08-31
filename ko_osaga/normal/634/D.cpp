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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

pi a[200005];
int s[200005];
int nxt[200005];

int main(){
	int n, cur, dist;
	cin >> dist >> cur >> n;
	int max = cur;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);
	stack<int> stk;
	for(int i=n-1; i>=0; i--){
		while(stk.size() && a[stk.top()].second >= a[i].second){
			stk.pop();
		}
		if(stk.size()) nxt[i] = stk.top();
		else nxt[i] = -1;
		stk.push(i);
	}
	cur -= a[0].first;
	lint ret = 0;
	for(int i=0; i<n; i++){
		if(cur < 0){
			puts("-1");
			return 0;
		}
		int needy = min(max, (nxt[i] == -1 ? dist : a[nxt[i]].first)- a[i].first);
		if(needy > cur){
			ret += 1ll * (needy - cur) * a[i].second;
			cur = needy;
		}
		cur -= (i == n-1 ? dist : a[i+1].first) - a[i].first;
	}
	if(cur < 0){
		puts("-1");
		return 0;
	}
	printf("%lld",ret);
}