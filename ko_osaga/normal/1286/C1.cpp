#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 2005;
const lint inf = 1e17;

int n;
int vect[105][26];
char dap[105];
vector<pair<string, int>> gph[MAXN];

bool vis[MAXN];

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	for(auto [u, v] : gph[x]){
		if(!dap[v]) {
			assert(sz(u) == 2);
			u.erase(find(all(u), dap[x]));
			dap[v] = u[0];
		}
		dfs(v);
	}
}

void solve(int l, int r){
	memset(vect, 0, sizeof(vect));
	printf("? %d %d\n", l + 1, r + 1);
	fflush(stdout);
	for(int i=l; i<=r; i++){
		for(int j=i; j<=r; j++){
			string s; cin >> s;
			for(auto &k : s){
				vect[sz(s)][k - 'a']++;
			}
		}
	}
	for(int i=r-l+1; i>0; i--){
		for(int j=0; j<26; j++){
			vect[i][j] -= vect[i - 1][j];
		}
	}
	for(int i=1; i<=r-l+1; i++){
		for(int j=0; j<26; j++){
			vect[i][j] -= vect[i + 1][j];
		}
	}
	int itr = 1;
	while(l <= r){
		string ans;
		for(int j=0; j<26; j++){
			while(vect[itr][j]){
				ans.push_back(j + 'a');
				vect[itr][j]--;
			}
		}
		if(l == r){
			dap[l] = ans[0];
			break;
		}
		gph[l].emplace_back(ans, r);
		gph[r].emplace_back(ans, l);
		l++;
		r--;
		itr++;
	}
}

int main(){
	cin >> n;
	if(n == 1){
		solve(0, 0);
	}
	else{
		solve(0, n - 1);
		solve(1, n - 1);
		solve(0, 0);
		dfs(0);
	}
	cout << "! " <<  dap << endl;
}