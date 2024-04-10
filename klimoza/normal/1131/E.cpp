#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 998244353;

pair<pair<bool, vector<ll>>, pair<ll, ll>> check(string st) {
	bool fl = true;
	ll cnt = 1;
	vector<ll> ans(26, 0);
	for (int i = 1; i < st.size(); i++) {
		if (st[i] == st[i - 1]) cnt++;
		else {
			ans[st[i - 1] - 'a'] = max(ans[st[i - 1] - 'a'], cnt);
			fl = false;
			cnt = 1;
		}
	}
	ans[st[st.size() - 1] - 'a'] = max(ans[st[st.size() - 1] - 'a'], cnt);
	ll cnt1 = 1;
	bool bl = true;
	for (int i = 1; i < st.size(); i++) {
		if (st[i] == st[i - 1]) cnt1++;
		else {
			break;
		}
	}
	ll cnt2 = 1;
	for (int i = st.size() - 2; i >= 0; i--) {
		if (st[i] == st[i + 1]) cnt2++;
		else {
			break;
		}
	}
	return { {fl, ans}, {cnt1, cnt2} };
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string st;
	cin >> st;
	ll maxi = 0;
	vector<ll> ans = check(st).first.second;
	for (int cnt = 1; cnt < n; cnt++) {
		cin >> st;
		auto f = check(st);
		if (f.first.first) {
			for (int i = 0; i < 26; i++) {
				if (st[0] - 'a' == i) {
					ans[i] = min((ll)1e9, (ans[i] + 1)) * min((ll)1e9, f.first.second[i]) + min((ll)1e9, ans[i]);
				}
				else {
					ans[i] = min(1LL, ans[i]);
				}
			}
		} 
		else {
			for (int i = 0; i < 26; i++) {
				ans[i] = min(1LL, ans[i]);
				ll t = ans[i];
				if (st[0] == st[st.size() - 1] && (i == st[0] - 'a') && ans[i]) {
					ans[i] = f.second.first + f.second.second + 1;
				}
				else {
					if (i == st[0] - 'a') {
						ans[i] = ans[i] + f.second.first;
					}
					if (i == st[st.size() - 1] - 'a') {
						ans[i] = max(ans[i], t + f.second.second);
					}
				}
			}
			//cout << f.second.first << " " << f.second.second << endl;
			for (int i = 0; i < 26; i++) {
				ans[i] = min((ll) 1e9, max(ans[i], f.first.second[i]));
				//cout << ans[i] << " ";
			}
			//cout << endl;
		}
	}
	for (ll i : ans) maxi = max(maxi, i);
	cout << maxi << endl;
	//system("pause");
	return 0;
}