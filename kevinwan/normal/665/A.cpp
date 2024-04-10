#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, ta, b, tb,h,m;
	scanf("%d%d%d%d", &a, &ta, &b, &tb);
	scanf("%d:%d", &h, &m);
	m += h * 60;
	m -= 300;
	printf("%d", (min(m + ta - 1,18*60+59) / b+1) - ((m - tb>=0)?(m-tb)/b+1:0));
	getchar(); getchar();
}