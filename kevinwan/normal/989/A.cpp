#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	bool a, b, c;
	for (int i = 1; i < s.size() - 1; i++) {
		a = 0; b = 0; c = 0;
		for (int j = i - 1; j <= i + 1; j++) {
			if (s[j] == 'A')a = 1;
			if (s[j] == 'B')b = 1;
			if (s[j] == 'C')c = 1;
		}
		if (a&&b&&c) {
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}