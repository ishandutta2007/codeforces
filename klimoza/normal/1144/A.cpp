#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
		
	int n;
	cin >> n;
	string st;
	while (n--) {
		cin >> st;
		vector<char> a(st.size());
		for (int i = 0; i < st.size(); i++) a[i] = st[i];
		sort(a.begin(), a.end());
		bool fl = false;
		for (int i = 1; i < st.size(); i++) {
			if (a[i] == a[i - 1]) {
				cout << "NO\n";
				fl = true;
				break;
			}
		}
		if (fl) continue;
		char mini = 'z';
		char maxi = 'a';
		for (char c : st) {
			mini = min(mini, c);
			maxi = max(maxi, c);
		}
		if (st.size() == maxi - mini + 1) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No\n";
		}
	}
	//system("pause");
	return 0;
}