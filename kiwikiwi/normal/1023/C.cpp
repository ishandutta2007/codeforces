#include <bits/stdc++.h>
using namespace std;

const int N = 234567;
int n, k, mark[N], cc;
char s[N];
stack<int> bracket;

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			bracket.push(i);
		} else {
			if (!bracket.empty() && s[bracket.top()] == '(') {
				mark[bracket.top()] = 1;
				mark[i] = 1;
				bracket.pop();
				cc += 2;
				if (cc == k) {
					for (int j = 0; j < n; j++) if (mark[j]) {
							printf("%c", s[j]);
						}
					puts("");
					return 0;
				}
			} else {
				bracket.push(i);
			}
		}
	}
}