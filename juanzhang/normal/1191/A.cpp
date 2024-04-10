#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	scanf("%d", &x);
	int t = x % 4;
	if (!t) {
		puts("1 A");
	} else if (t == 1) {
		puts("0 A");
	} else if (t == 2) {
		puts("1 B");
	} else {
		puts("2 A");
	}
  return 0;
}