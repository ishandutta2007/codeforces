#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

const int N = 1e5 + 10;
int dp[10][N], dp2[10][N];
pair<int, string> queries[N];
string t;

pair<int, int> get(const string & s, int k){
	int x = 0, y = 1;
	for(int i = 0; i < s.length(); i++){
		y = mul(y, dp2[s[i] - '0'][k]);
		x = add(mul(x, dp2[s[i] - '0'][k]), dp[s[i] - '0'][k]);
	}
	return {x, y};
}

int main(){
	cin.tie(0);
	string s;
	cin >> s;
	int q;
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> t;
		int d = stoi(t.substr(0, 1));
		t = t.substr(3, t.length() - 3);
		queries[i] = {d, t};
	}
	for(int i = 0; i < 10; i++){
		dp[i][q + 1] = i;
		dp2[i][q + 1] = 10;
	}
	for(int i = q; i >= 1; i--){
		int d = queries[i].first;
		t = queries[i].second;
		for(int j = 0; j < 10; j++){
			if(j != d){
				dp[j][i] = dp[j][i + 1];
				dp2[j][i] = dp2[j][i + 1];
			}
			else{
				pair<int, int> P = get(t, i + 1);
				dp[j][i] = P.first;
				dp2[j][i] = P.second;
			}
		}
	}
	pair<int, int> ans = get(s, 1);
	cout << ans.first;
}