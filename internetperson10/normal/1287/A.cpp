#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		int n, ans=0, curr=-1;
		cin >> n >> s;
		for(int a=0; a<n; a++) {
			if(s.at(a)=='A') {
				curr=0;
			}
			else if(curr>=0) {
				curr++;
			}
			ans=max(ans, curr);
		}
		cout << ans << '\n';
	}
}