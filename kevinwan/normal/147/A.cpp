#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	getline(cin, s);
	char mem = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i]<'a' || s[i]>'z') {
			mem = max(mem, s[i]);
			continue;
		}
		if (mem != 0) {
			if (mem != ' ')printf("%c", mem);
			printf(" ");
			mem = 0;
		}
		printf("%c", s[i]);
	}
	if (mem != 0 && mem != ' ')printf("%c", mem);
	getchar(); getchar();
}