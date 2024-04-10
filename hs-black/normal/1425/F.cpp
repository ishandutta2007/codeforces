
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

const int N = 50005;
int a[N], n;
ll ask(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	fflush(stdout);
	ll t; cin >> t; return t;
}
int main() {
	read(n);
	ll t1 = ask(1, 2), t2 = ask(1, 3), t3 = ask(2, 3);
	a[3] = t2 - t1, a[2] = t3 - a[3], a[1] = t1 - a[2];
	for (int i = 4;i <= n; i++)
		a[i] = ask(i-1, i) - a[i-1];
	cout << "! ";
	for (int i = 1;i <= n; i++) cout << a[i] << ' ';
	fflush(stdout);
	return 0;
}