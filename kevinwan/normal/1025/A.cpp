#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int am[26];
int main() {
	int n;
	string s;
	scanf("%d", &n);
	cin >> s;
	for (char c : s) {
		am[c - 'a']++;
	}
	bool ch = 0;
	for (int i = 0; i < 26; i++) {
		if (am[i] >= 2)ch = 1;
	}
	if (ch||n==1)printf("YES");
	else printf("NO");
	getchar(); getchar();
}