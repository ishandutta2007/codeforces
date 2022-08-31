#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define maxN 1234567

char s[maxN];

int main() {
	scanf("%s", s + 1);
	int l = 1, r = strlen(s + 1);
	string p1;
	while (r - l + 1 > 3) {
		if (s[l] == s[r]) {
			p1.push_back(s[l]);
			l++; r--;
		} else if (s[l] == s[r - 1]) {
			p1.push_back(s[l]);
			l++; r -= 2;
		} else if (s[l + 1] == s[r]) {
			p1.push_back(s[l + 1]);
			l += 2; r--;
		} else {
			assert(s[l + 1] == s[r - 1]);
			p1.push_back(s[l + 1]);
			l += 2; r -= 2;
		}
	}
	string p2 = p1;
	reverse(p2.begin(), p2.end());
	if (r - l + 1 >= 1) {
		p1.push_back(s[l]);
	}
	p1 += p2;
	printf("%s\n", p1.c_str());
}