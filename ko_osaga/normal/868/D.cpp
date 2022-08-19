#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 1005;
typedef long long lint;

string a[MAXN];
string pref[MAXN], suff[MAXN];

int n, m, s[MAXN], e[MAXN];
bool dp[205][15][1<<14];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		pref[i] = a[i];
		suff[i] = a[i];
		if(a[i].size() > 15) pref[i] = pref[i].substr(0, 15);
		if(a[i].size() > 15) suff[i] = suff[i].substr(suff[i].size() - 15, 15);
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<a[i].size(); j++){
			int ans = 0;
			for(int k=j; k<a[i].size(); k++){
				if(k - j + 1 > 14) break;
				ans = ans * 2 + (a[i][k] - '0');
				dp[i][k-j+1][ans] = 1;
			}
		}
	}
	cin >> m;
	for(int i=n+1; i<=n+m; i++){
		cin >> s[i] >> e[i];
		if(pref[s[i]].size() > 14) pref[i] = pref[s[i]];
		else pref[i] = pref[s[i]] + pref[e[i]];
		if(suff[e[i]].size() > 14) suff[i] = suff[e[i]];
		else suff[i] = suff[s[i]] + suff[e[i]];
		if(pref[i].size() > 15) pref[i] = pref[i].substr(0, 15);
		if(suff[i].size() > 15) suff[i] = suff[i].substr(suff[i].size() - 15, 15);
		for(int k=1; k<=14; k++){
			for(int j=0; j<(1<<k); j++){
				dp[i][k][j] |= (dp[s[i]][k][j] | dp[e[i]][k][j]);
			}
		}
		auto k = suff[s[i]] + pref[e[i]];
		for(int j=0; j<k.size(); j++){
			int ans = 0;
			for(int l=j; l<k.size(); l++){
				if(l - j + 1 > 14) break;
				ans = ans * 2 + (k[l] - '0');
				dp[i][l-j+1][ans] = 1;
			}
		}
		int ret = 0;
		for(int k=14; k; k--){
			bool ok = 1;
			for(int j=0; j<(1<<k); j++){
				if(dp[i][k][j] == 0) ok = 0;
			}
			if(ok){
				ret = k;
				break;
			}
		}
		cout << ret << endl;
	}
}