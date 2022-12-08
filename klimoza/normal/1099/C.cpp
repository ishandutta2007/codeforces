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
long double eps = 1e-8;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	string st;
	cin >> st;
	int k;
	cin >> k;
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	for (char c : st) {
		if (c == '*') cnt1++;
		else if (c == '?') cnt2++;
		else cnt3++;
	}
	if (cnt3 - cnt1 - cnt2 > k || (cnt1 == 0 && cnt3 < k)) cout << "Impossible\n";
	else if (cnt3 >= k) {
		int r = cnt3 - k;
		for (int i = 0; i < st.size() - 1; i++) {
			if (st[i] == '*' || st[i] == '?') continue;
			if (r && (st[i + 1] == '*' || st[i + 1] == '?')) {
				r--;
				continue;
			}
			cout << st[i];
		}
		if (st[st.size() - 1] != '*' && st[st.size() - 1] != '?') cout << st[st.size() - 1];
	}
	else {
		int r = k - (cnt3 - cnt1 - cnt2);
		for (int i = 0; i < st.size() - 1; i++) {
			if (st[i] == '*' || st[i] == '?' || st[i + 1] == '?') continue;
			if (st[i + 1] == '*') {
				while (r--) cout << st[i];
				r = 0;
				continue;
			}
			cout << st[i];
		}
		if (st[st.size() - 1] != '*' && st[st.size() - 1] != '?') cout << st[st.size() - 1];
	}
	//system("pause");
	return 0;
}