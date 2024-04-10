#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 1e8;
	for(int i=0;i<n-3;i++){
		int a = 0;
		a +=min( abs(s[i] - 'A'),26-abs(s[i] - 'A'));
		a +=min( abs(s[i+1] - 'C'),26-abs(s[i+1] - 'C'));
	a +=min( abs(s[i+2] - 'T'),26-abs(s[i+2] - 'T'));
		a +=min( abs(s[i+3] - 'G'),26-abs(s[i+3] - 'G'));
		ans=min(ans,a);
		
	}
	cout << ans;
	
}