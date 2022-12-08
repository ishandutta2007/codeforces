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

	cout.precision(15);
	string st;
	cin >> st;
	int n = st.size();
	vector<vector<vector<int>>> a(26, vector<vector<int>>(n, vector<int>(26)));
	vector<double> cnt(26);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			a[st[i] - 'a'][j - i][st[j] - 'a']++;
			a[st[j] - 'a'][i + n - j][st[i] - 'a']++;
		}
		cnt[st[i] - 'a']++;
	}
	double ans = 0;
	for (int i = 0; i < 26; i++) {
		double d1 = cnt[i] / n;
		double maxi = 0;
		for (int len = 1; len < n; len++) {
			double cur = 0;
			double cnt = 0;
			for (int j = 0; j < 26; j++) {
				if (a[i][len][j] == 1) cur += a[i][len][j];
				cnt += a[i][len][j];
			}
			maxi = max(maxi, d1 * cur / cnt);
			//cout << maxi << " " << i << " " << len << endl;
		}
		//cout << i << " " << maxi << endl;
		ans += maxi;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}