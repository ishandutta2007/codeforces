#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    string s;
    cin >> s;
    int n = s.size();
    int x, y;
    cin >> x >> y;
	if(y > x) {
		swap(x, y);
		for(int i = 0; i < n; i++) {
			if(s[i] == '?') {
				continue;
			}
			if(s[i] == '1') {
				s[i] = '0';
			} else {
				s[i] = '1';
			}
		}
	}
	vi pref0(n);
	pref0[0] = s[0] == '0';
	for(int i = 1; i < n; i++) {
		pref0[i] = pref0[i - 1] + ('0' == s[i]);
	}
	vi suff1(n);
	suff1[n - 1] = s[n - 1] == '1';
	for(int i = n - 2; i >= 0; i--) {
		suff1[i] = suff1[i + 1] + (s[i] == '1');
	}
	ll ans = 0;
	ll sum = 0;
	ll proz = (ll)pref0[n - 1] * (n - pref0[n - 1]);
	ll am01 = 0;
	int am1 = s[0] != '0';
	for(int i = 1; i < n; i++) {
		if(s[i] != '0') {
			am01 += pref0[i];
			++am1;
		}
	}
	sum = am01 * x + (proz - am01) * y;
	ans = sum;
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == '?') {
			--am1;
			proz = (ll)am1 * (n - am1);
			am01 -= pref0[i];
			am01 += suff1[i];
			ans = min(ans, am01 * x + (proz - am01) * y);
			//cout << i << ' ' << ans << endl;
		}
	}
	cout << ans;
}