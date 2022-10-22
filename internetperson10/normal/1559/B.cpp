#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int ans[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool sad = true, ch = false;
		for(int i = 0; i < n; i++) {
			if(s.at(i) == 'R' || s.at(i) == 'B') {
				if(sad) {
					sad = false;
					if(s.at(i) == 'R') ch = true;
					else ch = false;
					for(int j = i-1; j >= 0; j--) {
						ch ^= true;
						if(ch) ans[j] = 2;
						else ans[j] = 1;
					}
					if(s.at(i) == 'R') ch = true;
					else ch = false;
				}
				else {
					if(s.at(i) == 'R') ch = true;
					else ch = false;
				}
				if(ch) ans[i] = 2;
				else ans[i] = 1;
			}
			else if(!sad) {
				ch ^= true;
				if(ch) ans[i] = 2;
				else ans[i] = 1;
			}
			if(i+1 == n) {
				if(sad) {
					for(int j = 0; j < n; j+=2) ans[j] = 1;
					for(int j = 1; j < n; j+=2) ans[j] = 2;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			if(ans[i] == 1) cout << 'B';
			else cout << 'R';
		}
		cout << '\n';
	}
}