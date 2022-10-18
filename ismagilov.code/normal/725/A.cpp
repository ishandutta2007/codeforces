#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

const int maxn = 200001;
int n;
int g[maxn];
bool u[maxn];
bool u1[maxn];

bool dfs(int v){
	if (v == -1 || v == n){
		return 1;
	}
	else{
		if (u1[v] == 0){
			u1[v] = 1;
			return u[v] = dfs(g[v]);
		}
		else{
			return u[v];
		}
	}
}

main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++){
		if (s[i] == '<'){
			g[i] = i - 1;
		}
		else{
			g[i] = i + 1;
		}
	}
	for (int i = 0; i < n; i++){
		if (u1[i] == 0){
			int j = dfs(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans += u[i];
	}
	cout << ans;
}