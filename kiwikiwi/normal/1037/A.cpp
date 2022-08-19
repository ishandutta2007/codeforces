#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
	scanf("%d", &n);
	printf("%d\n", 32 - __builtin_clz(n));
}