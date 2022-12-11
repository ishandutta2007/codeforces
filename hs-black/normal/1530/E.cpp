#include <iostream>
#include <cstring>
#include <cstdio>
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

const int N = 200500;
int cnt[26], T, n, fist, sec, thr;
char s[N];
int main() {
	for (read(T); T; --T) {
		fist = sec = thr = -1;
		scanf ("%s", s + 1), n = strlen(s + 1);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1;i <= n; ++i) cnt[s[i] - 'a']++;
		for (int i = 0;i <= 25; ++i) if (cnt[i]) {
			if (fist == -1) { fist = i; continue; }
			if (cnt[i] == 1 && cnt[fist] != 1) fist = i;
		}
		putchar('a' + fist), cnt[fist]--;
		for (int i = 0;i <= 25; ++i) if (cnt[i] && fist != i) {
			if (sec == -1) sec = i;
			else if (thr == -1) thr = i;
		}
		if (sec > fist && cnt[fist] && (cnt[fist] - 1 <= (n - cnt[fist] - 1))) {
			putchar('a' + fist), --cnt[fist];
			for (int i = 0;i <= 25; ++i) if (i != fist) {
				while (cnt[i]) {
					putchar('a' + i), --cnt[i];
					if (cnt[fist]) putchar('a' + fist), --cnt[fist];
				}
			}
		} else if (cnt[fist] && thr != -1 && sec > fist) {
			putchar('a' + sec), --cnt[sec];
			while (cnt[fist]) putchar(fist + 'a'), --cnt[fist];
			putchar('a' + thr), --cnt[thr];
			while (cnt[sec]) putchar(sec + 'a'), --cnt[sec];
			while (cnt[thr]) putchar(thr + 'a'), --cnt[thr];
		}
		else if (sec != -1) while (cnt[sec]) putchar('a' + sec), --cnt[sec];
		for (int i = 0;i <= 25; ++i)
			while (cnt[i]) putchar('a' + i), --cnt[i];
		putchar('\n');
	}
	return 0;
}