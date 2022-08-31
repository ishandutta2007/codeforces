#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int M = 105;
int dp[N][M];
int nxt[N][27];
int choice[N][M];

string X;
string s; 

void trace(int i, int ans){
	if(ans <= 1){
		cout << X;
		if(ans) cout<<s[i];
		reverse(X.begin(), X.end());
		cout<<X<<endl;
		return;
	}
	if(choice[i][ans]){
		X.append(1, s[i]);
		ans -= 2;
	}
	trace(i + 1, ans);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> s;
	int n = s.length();
	for(int i = 0; i < 26; i++) nxt[n][i] = nxt[n + 1][i] = n;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			nxt[i][j] = (s[i] == 'a' + j) ? i : nxt[i + 1][j];
		}
	}
	for(int i = 0; i < M; i++) dp[n][i] = n;
	for(int i = n - 1; i >= 0; i--){
		dp[i][0] = i - 1;
		dp[i][1] = i;
		for(int j = 2; j <= n && j < M; j++){
			int x1 = dp[i + 1][j], x2 = nxt[dp[i + 1][j - 2] + 1][s[i] - 'a'];
			dp[i][j] = min(x1, x2);
			if(x1 > x2){
				choice[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n && i <= 100; i++) if(dp[0][i] != n) ans = i;
	trace(0, ans);
}