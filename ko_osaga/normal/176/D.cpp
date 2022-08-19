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

int n, m, a[2005];
string s[2005];
set<int> occu[2005][26];
set<int> occu2[2005];

string t;
pi dp[2005][2005];
bool vis[2005][2005];

pi next_occ(pi x, char t){
	int stp = x.second + 1;
	auto it = occu[a[x.first]][t - 'a'].lower_bound(stp);
	if(it != occu[a[x.first]][t - 'a'].end()){
		return pi(x.first, *it);
	}
	it = occu2[t - 'a'].lower_bound(x.first + 1);
	if(it == occu2[t - 'a'].end()) return pi(m+10, 0);
	x.first = *it;
	it = occu[a[x.first]][t - 'a'].begin();
	return pi(x.first, *it);
}

pi f(int x, int y){
	if(y == 0) return pi(0, -1);
	if(x == 0) return pi(m+10, 0);
	if(vis[x][y]) return dp[x][y];
	pi ret = f(x-1, y);
	ret = min(ret, next_occ(f(x-1, y-1), t[x-1]));
	vis[x][y] = 1;
	return dp[x][y] = ret;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> s[i];
		for(int j=0; j<s[i].size(); j++){
			occu[i][s[i][j]-'a'].insert(j);
		}
	}
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> a[i];
		for(int j=0; j<26; j++){
			if(occu[a[i]][j].size()) occu2[j].insert(i);
		}
	}
	cin >> t;
	for(int i=t.size(); i>=0; i--){
		if(f(t.size(), i).first <= m){
			printf("%d",i);
			return 0;
		}
	}
}