#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 200050;
int a[N];
char s[N];
int main() {
	int n, m;
	cin >> n >> m;
	scanf ("%s", s + 1);
	for (int i = 1;i <= n; i++) a[i] = s[i]-'0';
	if (m == 0) {
		printf ("%s", s + 1);
		return 0;
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (a[1] != 1) a[1] = 1, m--;
	for (int i = 2;i <= n; i++) {
		if (m == 0) break;
		if (a[i] == 0) continue;
		a[i] = 0, m--;
	}
	for (int i = 1;i <= n; i++) printf ("%d", a[i]);
	cout << endl;
	return 0;
}