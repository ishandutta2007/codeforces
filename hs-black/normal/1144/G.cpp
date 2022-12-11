#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 300050;
int a[N], ans[N];
int n, up = -1, down;

int main() {
	read(n); down = 1000000; 
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1;i <= n; i++) {
		int ca = 0;
		if (a[i] > up) ca++;
		if (a[i] < down) ca += 2;
		if (!ca) {
			cout << "NO\n";
			return 0;
		}
		if (ca == 3) {
			if (a[i] > a[i+1]) down = a[i], ans[i] = 1;
			else up = a[i];
		}
		else if (ca == 2) down = a[i], ans[i] = 1;
		else up = a[i];
	}
	cout << "YES\n";
	for (int i = 1;i <= n; i++) 
		printf ("%d ", ans[i]);
	return 0;
}