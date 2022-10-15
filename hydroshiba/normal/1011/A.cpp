#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	sort(s.begin(), s.end());
	
	char cur = s[0];
	int ans = s[0] - 'a' + 1, num = 1;
	
	for(int i = 1; i < s.size(); ++i) if(num < k && s[i] - cur > 1){
		cur = s[i];
		ans += cur - 'a' + 1;
		++num;
	}
	
	if(k != num) cout << -1;
	else cout << ans;
}