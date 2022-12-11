#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 200000;
int a[N], n, m;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
int main() {
	int T = read();
	while (T--) {
		int cnt = 0;
		n = read();
		for (int i = 1;i <= n; i++) a[i] = read();
		m = a[n];
		for (int i = n;i >= 1; i--) {
			if (m >= a[i])
				m = a[i];
			else cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}