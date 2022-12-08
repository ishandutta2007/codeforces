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
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<ll, ll>> pref(n);
	vector<pair<ll, ll>> suff(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	pref[0].second = a[0];
	if (n % 2 == 1) suff[n - 1].second = a[n - 1];
	else suff[n - 1].first = a[n - 1];
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			pref[i].first = pref[i - 1].first;
			pref[i].second = pref[i - 1].second + a[i];
		}
		else {
			pref[i].first = pref[i - 1].first + a[i];
			pref[i].second = pref[i - 1].second;
		}
		//cout << pref[i].first << " " << pref[i].second << endl;
	}
	for(int i = n - 2; i >= 0; i --){
		if (i % 2 == 0) {
			suff[i].first = suff[i + 1].first;
			suff[i].second = suff[i + 1].second + a[i];
		}
		else {
			suff[i].first = suff[i + 1].first + a[i];
			suff[i].second = suff[i + 1].second;
		}
	}
	for (int i = 0; i < n; i++) {
		ll t1 = pref[i].first + suff[i].second;
		ll t2 = pref[i].second + suff[i].first;
		//cout << pref[i].first << " " << suff[i].second << endl;
		if (t1 == t2) cnt++;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}