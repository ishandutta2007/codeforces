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

int n, a[100005], b[100005];
vector<int> cnd;
map<int, int> cnta, cntb, coincide;

int main(){
	scanf("%d",&n);
	int u = (n+1)/2;
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i],&b[i]);
		cnta[a[i]]++;
		cntb[b[i]]++;
		if(a[i] == b[i]) coincide[a[i]]++;
		cnd.push_back(a[i]);
		cnd.push_back(b[i]);
	}
	sort(cnd.begin(), cnd.end());
	cnd.resize(unique(cnd.begin(), cnd.end()) - cnd.begin());
	int ret = 1e9;
	for(auto &i : cnd){
		int u = (n+1)/2;
		if(cnta[i] + cntb[i] - coincide[i] < u) continue;
		ret = min(ret, max(0, u - cnta[i]));
	}
	if(ret > n) puts("-1");
	else cout << ret;
}