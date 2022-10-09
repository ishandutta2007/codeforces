#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	int a, b, c, d;
	scanf("%d:%d %d:%d", &a, &b, &c, &d);
	int x = 60*a + b - 60*c - d;
	x += 1440;
	x %= 1440;
	printf("%02d:%02d\n", x/60, x%60);
}