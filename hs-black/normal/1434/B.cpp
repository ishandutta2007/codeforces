
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 100500;
char s[3]; 
int a[N], T, n;
int st[N], id[N];
int ans[N], tp, cnt;
#define NO puts("NO")
vector<int> vec[N];

void merge(int x, int y) {
	if (vec[id[x]].size() < vec[id[y]].size()) swap(id[x], id[y]);
	for (auto t: vec[id[y]]) vec[id[x]].push_back(t);
}

int main() {
	read(n);
	for (int i = 1, x;i <= 2 * n; i++) {
		scanf ("%s", s);
		if (s[0] == '+') st[++tp] = 0, id[tp] = ++cnt, vec[cnt].push_back(cnt);
		else {
			read(x);
			if (!tp) return NO, 0;
			while (tp > 1 && st[tp-1] <= x) merge(tp-1, tp), tp--;
			if (st[tp] <= x) st[tp] = x;
			if (st[tp] != x) return NO, 0;
			ans[vec[id[tp]].back()] = x, vec[id[tp]].pop_back();
			if (!vec[id[tp]].size()) tp--;
		}
	}
	puts("YES");
	for (int i = 1;i <= n; i++) write(ans[i], ' ');
	return 0;
}