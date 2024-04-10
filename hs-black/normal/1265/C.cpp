#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x;
}

const int N = 405000;

int T, n;
int p[N], num[N];
int cnt;
int g, s, b;

int main() {
	T = read();
	while (T--) {
		n = read(); cnt = g = s = b = 0;
		for (int i = 1;i <= n; i++) {
			p[i] = read(); 
			if (p[i] != p[i-1]) cnt++;
			num[i] = cnt;
		}
		for (int i = 1;i <= n; i++) 
			if (num[i] == 1) g++;
		if (g * 3 + 2 > n / 2) {
			printf ("0 0 0\n");
			continue;
		}
		for (int i = g + 1;i <= n; ) {
			int bb = num[i], tmp = 0;
			while (num[i] == bb) tmp++, i++;
			if (i > n / 2 + 1) {
				if (s <= g || b <= g) {
					printf ("0 0 0\n");
					break;
				}
				printf ("%d %d %d\n", g, s, b);
				break;
			}
			if (s <= g) s += tmp;
			else b += tmp;
		}
	}
	return 0;
}