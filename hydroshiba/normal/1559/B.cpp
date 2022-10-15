#include "bits/stdc++.h"
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;

	int num = 0;
	for(int i = 0; i < n; ++i) if(s[i] == '?') ++num;

	if(num == n) s[0] = 'R', --num;

	while(num != 0){
		for(int i = 0; i < n; ++i) if(s[i] != '?'){
			char c = (s[i] == 'R' ? 'B' : 'R');
			if(i < n - 1 && s[i + 1] == '?') s[i + 1] = c, --num;
			if(i > 0 && s[i - 1] == '?') s[i - 1] = c, --num;
		}
	}

	cout << s << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();
}