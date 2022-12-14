#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5 + 4;
int n;
int sz[NS], chk[NS];
vector<vector<int>> way(NS);
vector<int> fib(30);
vector<int> num(NS, -1);
int sol(int x);
void getsz(int x){
	sz[x] = 1;
	chk[x] = 1;
	for(auto&nxt:way[x]){
		if(!chk[nxt]){
			getsz(nxt);
			sz[x] += sz[nxt];
		}
	}
	chk[x] = 0;
};
int dfs(int x, int pr, int l, int r){
	if(sz[x] == l || sz[x] == r){
		chk[pr] = 1;
		int rv = sol(x);
		chk[pr] = 0;
		if(rv){
			chk[x] = 1;
			rv = sol(pr);
			chk[x] = 0;
			if(rv){
				return 1;
			}
		}
	}
	for(auto&nxt:way[x]){
		if(nxt == pr || chk[nxt]){
			continue;
		}
		if(dfs(nxt, x, l, r)){
			return 1;
		}
	}
	return 0;
};
int sol(int x){
	getsz(x);
	if(sz[x] <= 3){
		return 1;
	}
	int l = fib[num[sz[x]] - 2], r = fib[num[sz[x]] - 1];
	return dfs(x, -1, l, r);
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fib[0] = fib[1] = 1;
	for(int i = 2; i < 30; ++i){
		fib[i] = fib[i - 2] + fib[i - 1];
		if(fib[i] < (int)num.size()){
			num[fib[i]] = i;
		}
	}
	for(int i = 0; i < n - 1; ++i){
		int x, y; cin >> x >> y; --x, --y;
		way[x].push_back(y), way[y].push_back(x);
	}
	cout << (sol(0) ? "YES\n" : "NO\n");
	return 0;
}