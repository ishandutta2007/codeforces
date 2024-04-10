#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;
    string ans = "";
    int n = s.size();
    if (n % 2 == 1) {
    	n--;
    }
    for (int i = 0; i < ((n + 2) / 4) * 2; i+= 2) {
    	vector<int> a(3, 0);
    	a[s[i] - 'a']++;
    	a[s[i + 1] - 'a']++;
    	a[s[n - 1 - i] - 'a']++;
    	a[s[n - 2 - i] - 'a']++;
    	if (a[0] >= 2) {
    		ans += 'a';
    	}
    	else if(a[1] >= 2) {
    		ans += 'b';
    	}
    	else {
    		ans += 'c';
    	}
    }
    cout << ans;
    reverse(ans.begin(), ans.end());
    if (n % 4 == 0) {
    	cout << ans;
    } else {
    	for (int i = 1; i < ans.size(); i++) {
    		cout << ans[i];
    	}
    }
}