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

int n, a[100005];

int bad[100005], sum[100005];
set<int> st;

bool ok(int s, int e){
	int u = sum[e-1] - sum[s-1];
	if(u == 0) return 1;
	auto t = *st.lower_bound(s);
	auto x = ++st.lower_bound(s);
	if(x != st.end() && *x < e) return 0;
	if(t + 2 > e || a[t] + 1 < a[t+2]) return 1;
	if(t - 1 < s || a[t-1] + 1 < a[t+1]) return 1;
	return 0;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<n; i++){
		if(a[i] >= a[i+1]) bad[i] = 1, st.insert(i);
		else bad[i] = 0;
		sum[i] = sum[i-1] + bad[i];
	}
	int e = 0, ret = 0;
	for(int i=1; i<=n; i++){
		e = max(e, i);
		while(e <= n && ok(i, e)) e++;
		ret = max(ret, e - i);
	}
	cout << ret;
}