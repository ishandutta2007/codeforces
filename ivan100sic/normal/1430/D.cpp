// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> a;
		char last = 0;
		int len = 0;
		for (char c : s) {
			if (c == last || !last) {
				len++;
				last = c;
			} else {
				a.push_back(len);
				len = 1;
				last = c;
			}
		}

		a.push_back(len);

		basic_string<int> pq;
		int k = a.size();
		for (int i=k-1; i>=0; i--) {
			if (a[i] > 1) {
				pq += i;
			}
		}

		int l = 0, sol = 0;
		while (l < k) {
			if (pq.size()) {
				sol++;
				int x = pq.back();
				pq.pop_back();
				a[x]--;
				l++;
				if (x >= l && a[x] > 1) {
					pq += x;
				}
			} else {
				sol += (k-l+1) / 2;
				break;
			}
		}

		cout << sol << '\n';
	}
}