#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<pair<int, int>> num;
	ll cure = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			num.push_back({ cure, a[i - 1] });
			cure = 1;
		}
		else {
			cure++;
		}
	}
	num.push_back({ cure, a[n - 1] });
	sort(num.begin(), num.end());
	ll maxi = num[num.size() - 1].first;
	ll ans = 0;
	ll cur = 0;
	ll st = 0;
	bool fl = false;
	for (int i = 1; i <= maxi; i++) {
		ll f = i;
		cur = 0;
		fl = false;
		for (int j = st; j < num.size(); j++) {
			//cout << num[j].first << " " << num[j].second << " ";
			if (f > maxi) break;
			if (num[j].first >= f) {
				if (!fl) {
					st = j;
				}
				fl = true;
				cur += f;
				f *= 2;
			}
		}
		//cout << "\n";
		ans = max(ans, cur);
	}
	cout << ans << "\n";
	//system("pause");  
	return 0;
}