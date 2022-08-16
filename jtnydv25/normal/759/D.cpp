#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e3 + 10, mod = 1e9 + 7;

int dp[N], n; 
long long dp2[N];
string s;
vector<int> vec;
bool came[26];
vector<int> nxt[N];
int main(){
	cin.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n;){
		int j = i;
		while(j < n && s[j] == s[i]) j++;
		vec.push_back(s[i] - 'a');
		i = j;
	}
	int m = vec.size();
	for(int j = 0; j < m; j++){
		memset(came, 0, sizeof came);
		for(int k = j + 1; k < m; k++){
			if(vec[k] != vec[j] && !came[vec[k]]){
				came[vec[k]] = 1;
				nxt[j].push_back(k);
			}
		}
		dp[j] = 1;
		dp2[j] = 1;
	}

	for(int l = 2; l <= n; l++){
		for(int i = 0; i < m; i++){
			long long res = 1;
			for(int j : nxt[i]) res += dp2[j];
			res %= mod;
			dp[i] = res;
		}
		for(int i = 0; i < m; i++) dp2[i] += dp[i];
	}
	memset(came, 0, sizeof came);
	long long ans = 0;
	for(int i = 0; i < m; i++){
		if(!came[vec[i]]){
			came[vec[i]] = 1;
			ans += dp[i];
		}
	}
	cout << ans % mod;
}