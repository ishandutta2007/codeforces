#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
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

const int N = 200500;
char st[N];
int n, T;

map <pair<int, int>, int> mp;

#define MP make_pair
int main() {
	read(T);
	while (T--) {
		read(n); mp.clear();
		scanf ("%s", st + 1);
		int s = 0, t = 0;
		int l = 0, r = n;
		mp[MP(0, 0)] = 0;
		for (int i = 1;i <= n; i++) {
			if (st[i] == 'L') s--;
			else if (st[i] == 'R') s++;
			else if (st[i] == 'U') t++;
			else if (st[i] == 'D') t--;
			if (mp.find(MP(s, t)) == mp.end()) mp[MP(s, t)] = i;
			else {
				int pre = mp[MP(s, t)];
				if (i - pre - 1 < r - l) l = pre + 1, r = i;
				mp[MP(s, t)] = i;
			}
		}
		if (l == 0) write(-1);
		else write(l), putchar(' '), write(r);
		putchar('\n');
	}
}