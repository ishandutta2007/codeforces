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

const int N = 300500;
int T, n;

struct Heap {
	priority_queue<int> q1, q2;
	void del(int x) {
		if (x != 0) q2.push(x);
	}
	void push(int x) {
		if (x != 0) q1.push(x);
	}
	int top(void) {
		while (q2.size() && q1.top() == q2.top()) q1.pop(), q2.pop();
		return q1.size() ? q1.top() : 0;
	}
	void clear(void) {
		while (q1.size()) q1.pop();
		while (q2.size()) q2.pop();
	}
}A;

char s[5];
int t[N], tp[6], q, x;
int main() {
		read(n); A.clear();
		for (int i = 1;i <= n; i++) 
			read(x), t[x]++, A.del(t[x]-1), A.push(t[x]);
		read(q);
		for (int i = 1;i <= q; i++) {
			scanf ("%s", s); read(x);
			if (s[0] == '+') {
				A.del(t[x]);
				t[x]++;
				A.push(t[x]);
			}
			else {
				A.del(t[x]);
				t[x]--;
				A.push(t[x]);
			}
			for (int j = 1;j <= 3; j++) 
				tp[j] = A.top(), A.del(A.top());
			int fl = 1;
			if (tp[1] < 4) fl = 0;
			else {
				int k = (tp[1] - 4) / 2;
				k += (tp[2] / 2) + (tp[3] / 2);
				if (k < 2) fl = 0;
			}
			if (fl) puts("YES");
			else puts("NO");
			for (int j = 1;j <= 3; j++) A.push(tp[j]);
		}
	return 0;
}