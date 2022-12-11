#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

int T; char s[30];
int check(int fl) {
	int fi = 0, se = 0;
	for (int i = 1;i <= 10; ++i) {
		if (s[i] == '?') i & 1 ? fi += fl : se += !fl;
		else {
			int c = (s[i] - '0');
			i & 1 ? fi += c : se += c;
		}
		if (fi > (11 - i) / 2 + se) return i;
		if (se > (10 - i) / 2 + fi) return i;
	}
	return 10;
}

int main() {
	for (read(T); T; --T) {
		scanf ("%s", s + 1);
		write(min(check(0), check(1)));
	}
	return 0;
}