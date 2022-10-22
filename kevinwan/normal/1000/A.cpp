#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[9], b[9];
int t(string s) {
	if (s.size() > 1)return s[s.size() - 1] == 'L' ? 4 + s.size() : 4 - s.size();
	if (s[0] == 'M')return 4;
	if (s[0] == 'L')return 5;
	if (s[0] == 'S')return 3;
}
int main() {
	int n,i;
	scanf("%d", &n);
	string s;
	for (i = 0; i < n; i++)cin >> s, a[t(s)]++;
	for (i = 0; i < n; i++)cin >> s, b[t(s)]++;
	int ans = 0;
	for (i = 0; i < 9; i++)ans += abs(a[i] - b[i]);
	printf("%d", ans / 2);
	getchar(); getchar();
}