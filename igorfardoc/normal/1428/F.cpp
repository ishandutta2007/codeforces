#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
string s;

ll calc(string s, int mid) {
	/*for(const auto& el : s) {
		cout << el;
	}
	cout << ' ' << mid << endl;*/
	int n = s.size();
	int amleft = 0;
	int amright = 0;
	for(int i = mid + 1; i < n; i++) {
		if(s[i] == '1') {
			++amright;
		} else {
			break;
		}
	}
	for(int i = mid; i >= 0; i--) {
		if(s[i] == '1') {
			++amleft;
		} else {
			break;
		}
	}
	vi max1(n - mid - 1);
	int now = amleft;
	ll sum = 0;
	for(int i = mid + 1; i < n; i++) {
		if(s[i] == '1') {
			++now;
		} else {
			now = 0;
		}
		if(i == mid + 1) {
			max1[i - mid - 1] = max(amleft, now);
		} else {
			max1[i - mid - 1] = max(max1[i - mid - 2], now);
		}
		sum += max1[i - mid - 1];
	}
	int pt = mid + 1;
	ll ans = 0;
	int heremax = 0;
	now = 0;
	for(int i = mid - amleft; i >= 0; i--) {
		if(s[i] == '1') {
			++now;
		} else {
			now = 0;
		} 
		heremax = max(heremax, now);
		while(pt < n && max1[pt - mid - 1] <= heremax) {
			sum -= max1[pt - mid - 1];
			++pt;
		}
		ans += sum + (ll)heremax * (pt - mid - 1);
	}
	return ans;
}

ll rec(int l, int r) {
	//cout << l << ' ' << r << endl;
	if(l == r) {
		if(s[l] == '1') {
			return 1;
		}
		return 0;
	}
	int mid = (l + r) / 2;
	ll ans = rec(l, mid) + rec(mid + 1, r);
	int amleft = 0;
	int amright = 0;
	for(int i = mid + 1; i <= r; i++) {
		if(s[i] == '1') {
			++amright;
		} else {
			break;
		}
	}
	for(int i = mid; i >= l; i--) {
		if(s[i] == '1') {
			++amleft;
		} else {
			break;
		}
	}
	for(int i = mid; i > mid - amleft; i--) {
		int max1 = amright + mid - i + 1;
		int min1 = mid - i + 2;
		ans += (ll)(max1) * (max1 + 1) / 2;
		ans -= (ll)(min1) * (min1 - 1) / 2;
	}
	string s1 = "";
	for(int i = l; i <= r; i++) {
		s1 += s[i];
	}
	ans += calc(s1, mid - l);
	if(amleft > 0) {
		s1 = "";
		for(int i = r; i > mid - amleft; i--) {
			s1 += s[i];
		}
		ans += calc(s1, r - mid - 1);
	}
	//cout << l << ' ' << r << ' ' << ans << endl;
	return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    cin >> s;
    cout << rec(0, n - 1);
}