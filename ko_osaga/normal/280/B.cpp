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

int n, a[100005], ret;

void solve(){
	vector<int> stk;
	for(int i=0; i<n; i++){
		while(!stk.empty() && stk.back() < a[i]){
			ret = max(ret, stk.back() ^ a[i]);
			stk.pop_back();
		}
		stk.push_back(a[i]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	solve();
	reverse(a,a+n);
	solve();
	cout << ret;
}