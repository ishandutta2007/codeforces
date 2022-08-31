#include <bits/stdc++.h>
using namespace std;
char c[100005];
int main() {
	int n; cin >> n;
	scanf("%s", c + 1);
	sort(c + 1, c + n + 1);
	printf("%s\n", c + 1);
	return 0;
}