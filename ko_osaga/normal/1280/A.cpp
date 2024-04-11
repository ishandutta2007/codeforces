#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 600005;
const int mod = 1e9 + 7;

char buf[MAXN];
void solve(){
	int n;
	scanf("%d",&n);
	scanf("%s", buf);
	string S = buf;
	int ptr = 0;
	while(sz(S) < n){
		if(S[ptr] == '2'){
			auto g = S.substr(ptr + 1, sz(S));
			for(int i=0; i<sz(g); i++) S.push_back(g[i]);
		}
		if(S[ptr] == '3'){
			auto g = S.substr(ptr + 1, sz(S));
			for(int i=0; i<sz(g); i++) S.push_back(g[i]);
			for(int i=0; i<sz(g); i++) S.push_back(g[i]);
		}
		ptr++;
	}
	S.resize(n);
	lint ans = strlen(buf);
	for(int i=1; i<=n; i++){
		int cnt = S[i-1] - '0';
		ans = (ans  + mod - i) * cnt + i;
		ans %= mod;
	}
	cout << ans << endl;;
}

int main(){
	int tc = 0;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
}