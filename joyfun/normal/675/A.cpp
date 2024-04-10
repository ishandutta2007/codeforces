#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
//lower_bound(a+1,a+1+len1,x) - a - 1;
typedef long long LL;

using namespace std;

int a, b, c;

bool judge() {
	if (c == 0) return a == b;
	if (a < b && c < 0) return false;
	if (a > b && c > 0) return false;	
	return (b - a) % c == 0;
}

int main() {
	scanf("%d%d%d", &a, &b, &c);
	printf("%s", judge() ? "YES" : "NO");

	return 0;
}