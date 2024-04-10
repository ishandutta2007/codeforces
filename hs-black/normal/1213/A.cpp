#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main() {
	int a = 0, b = 0, n;
	cin >> n;
	for (int i = 1;i <= n; i++) {
		int x;
		scanf ("%d", &x);
		if (x & 1) a++;
		else b++;
	}
	printf ("%d\n", min(a, b));
	return 0;
}