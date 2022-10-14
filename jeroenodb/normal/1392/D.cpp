#include <iostream>
#include <bitset>
#include <vector>
#include <tuple>
using namespace std;
#define D(a) \
    do { cout << #a ": " << (a) << ' '; } while(false)

const int mxN = 2e5 + 1;

int n, a[mxN] = {}, b[mxN];

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		char cur = s[0];
		bool whole = true;
		for (int i = 1; i < n; ++i) {
			if (s[i] != cur) {
				whole = false;
				break;
			}
		}
		if (whole) {
			int left = n-1,ans=1;
			ans+=left/3;
			cout << ans << endl; continue;
		}
		int len = 1,ans=0;
		int end = n;
		if (s[0] == s[n - 1]) {
			len++;
			for (int i = n - 2; i >= 0; --i) {
				if (s[i] != cur) {
					end = i + 1;
					break;
				} else {
					len++;
				}
			}
		}
		for (int i = 1; i < end; ++i) {
			if (cur != s[i]) {
				cur = s[i];
				ans += len / 3;
				len = 1;
			}
			else {
				len++;
			}
		}
		ans += len /3;
		cout << ans << endl;

	}
}