#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	long long ans = 1;
	long long m = 1e9+7;
	string s;
	cin >> s;
	s+="a";
	int n = s.length();

	vector<long long>dp(n+1);
	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for(int i = 3; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
		dp[i]%=m;
	}
	long long total = 1;
	bool f = true;
	for(int i = 0; i<n; i++){
		if(s[i]=='m'||s[i]=='w')f = false;
	}
	for(int i = 0; i<n; i+=0){
		if(s[i]=='u'){
			int j = i;
			for(; j<n; j++){
				if(s[j]!='u'){
					break;
				}
			}
			total*=dp[j-i];
			total%=m;
			i = j;
		}
		else if(s[i]=='n'){
			int j = i;
			for(; j<n; j++){
				if(s[j]!='n'){
					break;
				}
			}
			total*=dp[j-i];
			total%=m;
			i = j;
		}
		else{
			i++;
		}
	}
	if(!f)cout << "0\n";
	else
	cout << total << "\n";
	return 0;
}