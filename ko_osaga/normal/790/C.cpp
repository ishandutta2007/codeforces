#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

vector<int> v[3];
int n;
char str[100];
int dp[80][80][80][2];

int f(int na, int nb, int nc, int pa){
	if(na + nb + nc == n) return 0;
	if(~dp[na][nb][nc][pa]) return dp[na][nb][nc][pa];
	int ret = 1e9;
	if(na < v[0].size()){
		int nxt = v[0][na];
		int tmp = 0;
		for(int i=0; i<na; i++) if(v[0][i] > nxt) tmp++;
		for(int i=0; i<nb; i++) if(v[1][i] > nxt) tmp++;
		for(int i=0; i<nc; i++) if(v[2][i] > nxt) tmp++;
		ret = min(ret, tmp + f(na+1, nb, nc, 1));
	}
	if(nb < v[1].size() && !pa){
		int nxt = v[1][nb];
		int tmp = 0;
		for(int i=0; i<na; i++) if(v[0][i] > nxt) tmp++;
		for(int i=0; i<nb; i++) if(v[1][i] > nxt) tmp++;
		for(int i=0; i<nc; i++) if(v[2][i] > nxt) tmp++;
		ret = min(ret, tmp + f(na, nb+1, nc, 0));
	}
	if(nc < v[2].size()){
		int nxt = v[2][nc];
		int tmp = 0;
		for(int i=0; i<na; i++) if(v[0][i] > nxt) tmp++;
		for(int i=0; i<nb; i++) if(v[1][i] > nxt) tmp++;
		for(int i=0; i<nc; i++) if(v[2][i] > nxt) tmp++;
		ret = min(ret, tmp + f(na, nb, nc+1, 0));
	}
	return dp[na][nb][nc][pa] = ret;
}

int main(){
	cin >> n >> str;
	for(int i=0; i<n; i++){
		if(str[i] == 'V') v[0].push_back(i);
		else if(str[i] == 'K') v[1].push_back(i);
		else v[2].push_back(i);
	}
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0, 0, 0);
}