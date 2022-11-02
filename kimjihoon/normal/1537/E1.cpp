#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int t = 0;
	for (int i = 1; i < n; i++) {
		int ti = 0, tj = 0;
		for (int j = 0; j < k; j++) {
			if (s[ti] < s[tj]) break;
			if (s[ti] > s[tj]) {
				t = i;
				break;
			}
			ti = (ti + 1) % (t + 1); tj = (tj + 1) % (i + 1);
		}
	}
	int ti = 0;
	for (int i = 0; i < k; i++) {
		cout << s[ti];
		ti = (ti + 1) % (t + 1);
	}
	cout << '\n';
	return 0;	
}