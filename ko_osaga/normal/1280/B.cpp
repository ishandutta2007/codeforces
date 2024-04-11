#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 100;
const int mod = 1e9 + 7;

int n, m;
char str[MAXN][MAXN];

int cnt(int sx, int ex, int sy, int ey, char c){
	int ret = 0;
	for(int i=sx; i<=ex; i++){
		for(int j=sy; j<=ey; j++){
			if(str[i][j] == c) ret++;
		}
	}
	return ret;
}

void solve(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++) scanf("%s", str[i]);
	if(cnt(0, n - 1, 0, m - 1, 'A') == 0){
		puts("MORTAL");
		return;
	}
	if(cnt(0, n - 1, 0, m - 1, 'P') == 0){
		puts("0");
		return;
	}
	if(
		cnt(0, 0, 0, m - 1, 'P') == 0 ||
		cnt(n-1, n-1, 0, m - 1, 'P') == 0 ||
		cnt(0, n-1, 0, 0, 'P') == 0 ||
		cnt(0, n-1, m-1, m-1, 'P') == 0){
		puts("1");
		return;
	}
	for(int i=0; i<n; i++){
		if(cnt(i, i, 0, m-1, 'P') == 0){
			puts("2");
			return;
		}
	}
	for(int i=0; i<m; i++){
		if(cnt(0, n-1, i, i, 'P') == 0){
			puts("2");
			return;
		}
	}
	if(str[0][0] == 'A' || str[n-1][m-1] == 'A' || str[0][m-1] == 'A' || str[n-1][0] == 'A'){
		puts("2");
		return;
	}
	if(
		cnt(0, 0, 0, m - 1, 'A') == 0 &&
		cnt(n-1, n-1, 0, m - 1, 'A') == 0 &&
		cnt(0, n-1, 0, 0, 'A') == 0 &&
		cnt(0, n-1, m-1, m-1, 'A') == 0){
		puts("4");
		return;
	}
	puts("3");
}

int main(){
	int tc = 0;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
}