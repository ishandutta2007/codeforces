#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	vector<vector<long long> > freq(26, vector<long long>(26, 0));
	vector<long long> cfreq(26, 0);
	int n = (int)s.size();
	long long ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			freq[j][s[i]-'a'] += cfreq[j];
		}
		cfreq[s[i]-'a']++;
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			ans = max(ans, freq[i][j]);
		}
		ans = max(ans, cfreq[i]);
	}
	cout << ans << endl;
}