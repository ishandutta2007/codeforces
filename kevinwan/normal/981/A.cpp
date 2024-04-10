#include <bits/stdc++.h>
using namespace std;
bool ispal(string s) {
	for (int i = 0; i < s.size() / 2;i++)if (s[i] != s[s.size() - 1 - i])return 0;
	return 1;
}
int main() {
	string s;
	cin >> s;
	int n = s.size(),i,j;
	for (i = n; i >= 2; i--) {
		for (j = 0; j + i - 1 < n; j++) {
			if (!ispal(s.substr(j, i))) {
				printf("%d", i);
				return 0;
			}
		}
	}
	printf("0");
}