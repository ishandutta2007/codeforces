#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

string s;

const int N = 205;
int dp[N][N][N];
int main(){
	int n = 0;
	cin >>n >> s;
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'B')a++;
		else if(s[i] == 'G') b++;
		else c++;
	}

	for(int sm = 0; sm <= n; sm++){
		for(int i = 0; i <= sm; i++){
			for(int j = 0; i + j <= sm; j++){
				int k = sm - i - j;
				if(i == 0 && j == 0 && k == 0) continue;

				if(i == 0 && j == 0 && k == 1) dp[i][j][k] = (1 << 2);
				if(i == 0 && j == 1 && k == 0) dp[i][j][k] = (1 << 1);
				if(i == 1 && j == 0 && k == 0) dp[i][j][k] = (1 << 0);

				if(i + j + k == 1) continue;

				if(i >= 2) dp[i][j][k] |= (dp[i - 1][j][k]);
				if(j >= 2) dp[i][j][k] |= (dp[i][j - 1][k]);
				if(k >= 2) dp[i][j][k] |= (dp[i][j][k - 1]);

				if(i >= 1 && j >= 1 && k + 1 < N) dp[i][j][k] |= dp[i - 1][j - 1][k + 1];

				if(i + 1 < N && j >= 1 && k >= 1) dp[i][j][k] |= dp[i + 1][j - 1][k - 1];

				if(i >= 1 && j + 1 < N && k >= 1) dp[i][j][k] |= dp[i - 1][j + 1][k - 1];
			}
		}
	}
	string ans = "";
	if(dp[a][b][c] & (1 << 0)) ans += "B";
	if(dp[a][b][c] & (1 << 1)) ans += "G";
	if(dp[a][b][c] & (1 << 2)) ans += "R";

	cout << ans;
}