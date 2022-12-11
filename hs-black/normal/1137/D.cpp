
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

ll bit;

int get(void) {
	int num; read(num);
	for (int i = 1;i <= num; i++) 
		read(bit);
	return num;
}

void work(void) {
	printf ("next "), write(0);
	fflush(stdout), get();
	printf ("next "), write(0, ' '), write(1);
	fflush(stdout);
}

void workall(void) {
	printf ("next ");
	for (int i = 0;i < 10; i++)
		write(i, ' ');
	puts(""); fflush(stdout);
}

int main() {
	while(1) {
		work();
		if (get() == 2) break;
	}
	while (1) {
		workall();
		if (get() == 1) break;
	}
	puts("done"); fflush(stdout);
	return 0;
}