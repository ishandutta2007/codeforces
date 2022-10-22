#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int n,k;
	scanf("%d%d", &n,&k);
	cin >> s;
	char i; int j;
	for (i = 'a'; i <= 'z'; i++) {
		for (j = 0; j < n; j++) {
			if (s[j] != i)continue;
			if (k-- > 0)s[j] = 0;
		}
	}
	for (char c : s)if (c != 0)printf("%c", c);
	getchar(); getchar();
}