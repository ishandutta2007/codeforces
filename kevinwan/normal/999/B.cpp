#include <bits/stdc++.h>
using namespace std;
int main() {
	string s,t;
	int n;
	scanf("%d", &n);
	cin >> s;
	int i,j;
	for (i = 1; i <= n; i++) {
		if (n%i != 0)continue;
		for (j = 0; j < i / 2; j++)s[j] ^= s[i - 1 - j] ^= s[j] ^= s[i - 1 - j];
	}
	cout << s;
	getchar(); getchar();
}