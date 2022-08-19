#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 100005;

int n, k;
set<int> s[2];
int l[MAXN][2];
int r[MAXN][2];
char str[MAXN];

bool win(pi *x){
	return x[0].second - x[0].first <= k - 1 || x[1].second - x[1].first <= k - 1;
}

pi solve(int p, int l, int r){
	pi ret(1e9, -1e9);
	auto i = s[p].lower_bound(l);
	if(i != s[p].end() && *i <= r) ret.first = *i;
	i = s[p].upper_bound(r);
	if(i != s[p].begin() && *prev(i) >= l) ret.second = *prev(i);
	return ret;
}

int main(){
	scanf("%d %d %s",&n,&k,str+1);
	memset(l, 0x3f, sizeof(l));
	for(int i=1; i<=n; i++){
		s[str[i] - '0'].insert(i);
	}
	if(s[0].empty() || s[1].empty()){
		puts("tokitsukaze");
		return 0;
	}
	if(*s[0].rbegin() - *s[0].begin() <= k - 1 || *s[1].rbegin() - *s[1].begin() <= k - 1){
		puts("tokitsukaze");
		return 0;
	}
	bool shouldLose = 1;
	for(int i=1; i+k-1<=n; i++){
		pi intv[2];
		for(int j=0; j<2; j++){
			auto x = solve(j, 1, i - 1);
			auto y = solve(j, i + k, n);
			intv[j].first = min(x.first, y.first);
			intv[j].second = max(x.second, y.second);
		}
		for(int j=0; j<2; j++){
			pi nintv[2];
			nintv[0] = intv[0];
			nintv[1] = intv[1];
			nintv[j].first = min(nintv[j].first, i);
			nintv[j].second = max(nintv[j].second, i + k - 1);
			if(!win(nintv)) shouldLose = 0;
		}
	}
	if(shouldLose) puts("quailty");
	else puts("once again");
}