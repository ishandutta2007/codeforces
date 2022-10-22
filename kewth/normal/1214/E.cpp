#if 0
2019.09.04

 di  (x, y) 

 a[i]  i 
 a[k]  di  (x, y) 
 a[k] = x  a[k + di - 1]  y 

 di  y 

 di <= n  a 
 di, (x, y) x  a[1] y  a[di - 1]  di = 1 
#endif
#include <cstdio>
#include <stack>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 200005;
std::stack<int> D[maxn << 1];
int a[maxn << 1];
std::stack<int> A[maxn << 1];

int main() {
	int n = input();

	int max = 0;

	for(int i = 1; i <= n; i ++) {
		int d = input();
		D[d].push(i);
		max = std::max(max, d);
	}

	a[1] = D[max].top() * 2;
	a[max + 1] = D[max].top() * 2 - 1;
	D[max].pop();

	int now = 2;

	for(int d = max; d; d --)
		while(not D[d].empty()) {
			int x = D[d].top();
			D[d].pop();

			if(now <= max) {
				a[now] = x * 2;
				A[now + d].push(x * 2 - 1);
				now ++;
			}

			else {
				if(d == 1) {
					D[d].push(x);
					break;
				}
				A[0].push(x * 2);
				A[d].push(x * 2 - 1);
			}
		}

	while(not D[1].empty()) {
		int x = D[1].top();
		D[1].pop();
		printf("%d %d\n", a[1], x * 2);
		printf("%d %d\n", x * 2, x * 2 - 1);
	}

	int en = max + 1;
	while(not A[en + 1].empty()) {
		++ en;
		a[en] = A[en].top();
		A[en].pop();
	}

	for(int i = 1; i < en; i ++)
		printf("%d %d\n", a[i], a[i + 1]);

	for(int i = 2; i <= en; i ++)
		while(not A[i].empty()) {
			printf("%d %d\n", a[i - 1], A[i].top());
			A[i].pop();
		}

	while(not A[0].empty()) {
		printf("%d %d\n", a[1], A[0].top());
		A[0].pop();
	}
}