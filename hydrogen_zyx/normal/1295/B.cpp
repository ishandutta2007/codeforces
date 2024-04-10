#include<iostream>
#include<cstring>
using namespace std;
char s[100010];
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		long long n, x, cnt = 0;
		cin >> n >> x;
		cin >> s;
		long long d, cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') cnt1++;
			else cnt0++;
		}
		d = cnt0 - cnt1;
		if (d == 0) {
			int dd = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '1') dd--;
				else dd++;
				if (dd == x) {
					cnt = -1;
					break;
				}
			}
		}
		else {
			int dd = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '1') dd--;
				else dd++;
				if ((x - dd) % d == 0 && (x - dd) * d >= 0) cnt++;
			}
			if (x == 0) cnt++;
		}
		cout << cnt << endl;
	}
}