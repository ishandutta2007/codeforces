#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int p[200001];



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    p[0] = 1;
    for(int i = 1; i <= 200000; i++) {
    	p[i] = ((ll)p[i - 1] * 3) % mod;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = 0;
    vi pref(n + 1, 0), suff(n + 1, 0);
    for(int i = 1; i <= n; i++) {
    	pref[i] = pref[i - 1] + (s[i - 1] == 'a');
    	k += s[i - 1] == '?';
    }
    for(int i = n - 1; i >= 0; i--) {
    	suff[i] = suff[i + 1] + (s[i] == 'c');
    }
    int ans = 0;
    int now = 0;
    for(int i = 0; i < n; i++) {
    	if(s[i] == 'c' || s[i] == 'a') {
    		continue;
    	}
    	if(s[i] == 'b') {
    		ans = ((ll)pref[i] * suff[i] % mod * p[k] + ans) % mod;
    	} else {
    		ans = ((ll)pref[i] * suff[i] % mod * p[k - 1] + ans) % mod;
    	}
    	int left = now;
    	int right = k - left - (s[i] == '?');
    	if(left > 0 && right > 0) {
    		ans = ((ll)left * right % mod * p[left + right - 2] + ans) % mod;
    	}
    	if(right > 0) {
    		ans = ((ll)right * pref[i] % mod * p[left + right - 1] + ans) % mod;
    	}
    	if(left > 0) {
    		ans = ((ll)left * suff[i] % mod * p[right + left - 1] + ans) % mod;
    	}
    	if(s[i] == '?') {
    		++now;
    	}
    }
    cout << ans;
}