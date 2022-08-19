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
const int mod = 1e9 + 7;

int n, k;
string s;
int ps[100005];

bool trial(int x){
	for(int i=0; i<n; i++){
		if(s[i] == '1') continue;
		int ed = i + x, st = i - x - 1;
		ed = min(ed, n-1), st = max(st, -1);
		int u = ps[ed] - (st >= 0 ? ps[st] : 0);
		if(u >= k+1) return 1;
	}
	return 0;
}
int main(){
	cin >> n >> k >> s;
	for(int i=0; i<s.size(); i++){
		if(i) ps[i] = ps[i-1];
		if(s[i] == '0') ps[i]++;
	}
	int st = 0, ed = n;
	while(st != ed){
		int m = (st+ed)/2;
		if(trial(m)) ed = m;
		else st = m+1;
	}
	cout << ed;
}