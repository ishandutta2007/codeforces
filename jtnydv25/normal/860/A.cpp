#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int dp[N];
int pos[N];
inline bool test(char c){
	return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}
inline bool test(char c1, char c2, char c3){
	return test(c1) && test(c2) && test(c3) && (c1 != c2 || c2 != c3);
}

int main(){
	string s;
	cin >> s;
	int n = s.length();
	s = " " + s;
	for(int i = 1; i <= n; i++) dp[i] = 1000000000;
	bool w = 1;
	for(int i = 1; i <= n; i++){
		if(i >= 3 && test(s[i], s[i - 1], s[i - 2])) w = 0;
		if(w){
			dp[i] = 0;
			pos[i] = 0;
			continue;
		}

		bool wrong = 0;

		for(int j = i; j >= 1; j--){
			if(i - j + 1 >= 3){
				if(test(s[j], s[j + 1], s[j + 2])){
					wrong = 1;
				}
			}
			if(!wrong){
				if(dp[j - 1] + 1 < dp[i]){
					dp[i] = dp[j - 1] + 1;
					pos[i] = j - 1;
				}
			}
		}
	}
	string res;
	int i = n;
	for(; i;){
		for(int k = i; k > pos[i]; k--) res.append(1, s[k]);
		i = pos[i];
		if(i) res += " ";
	}
	reverse(res.begin(), res.end());
	cout << res;
}