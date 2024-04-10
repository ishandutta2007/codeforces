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

main() {
	ios_base::sync_with_stdio(0);
	string s;
	
	cin >> s;
	int n = len(s);
	char ans[n];
	for (int i = 0; i < n; i++){
		ans[i] = s[i];
	}
	bool u[36];
	int tek = 0;
	for (int i = 0; i <= n - 26; i++){
		for (int j = 0; j < 26; j++){
			u[j] = 0;
		}
		tek = 0;
		for (int j = i; j < i + 26; j++){
			if (s[j] == '?'){
				tek++;
			}
			else{
				u[s[j] - 'A'] = 1;
			}
		}
		vector <int> now;
		for (int j = 0; j < 26; j++){
			tek += u[j];
			if (!u[j]) now.push_back(j);  
		}
		if (tek == 26){
			for (int j = i; j < i + 26; j++){
				if (s[j] == '?' && now.size() > 0){
					ans[j] = (char)((int)(now[0]) + 'A');
				    now.erase(now.begin());
				}
			}	
			for (int j = 0; j < n; j++){
				if (ans[j] == '?'){
					ans[j] = 'A';
				}
				cout << ans[j];
			}
			return 0;
		}

	}
	cout << -1;
	
}