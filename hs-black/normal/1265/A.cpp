#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 105000;
char s[N];
inline bool check(int x) {
	if (s[x] == s[x-1] || s[x] == s[x+1]) return false;
	return true;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int flag = 0;
		scanf ("%s", s + 1);
		int n = strlen(s + 1);
		for (int i = 1;i <= n; i++) {
			if (s[i] == s[i-1]) {
				flag = 1; break;
			}
			if (s[i] == '?') {
				s[i] = 'a';
				if (check(i)) continue;
				s[i] = 'b';
				if (check(i)) continue;
				s[i] = 'c';
				if (check(i)) continue;
			}
		}
		if (flag) {
			printf ("-1\n");
			continue;
		}
		for (int i = 1;i <= n; i++) 
			printf ("%c", s[i]);
		putchar('\n');
	}
	return 0;
}