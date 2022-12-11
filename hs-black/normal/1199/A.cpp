#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<deque>
using namespace std;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}

int n, x, y;
const int N = 1000005;
int a[N];

deque<int> q;

int main() {
	n = read(), x = read(), y = read();
	for (int i = 1;i <= n; i++)
		a[i] = read();
	for (int i = 1 - y;i <= n; i++) {
		if (i + y <= n) 
		while (!q.empty() && a[i + y] <= q.back()) q.pop_back();
		q.push_back(a[i + y]);
		if (i > 0) {
			if (i > x + 1) if (q.front() == a[i-x-1]) q.pop_front();
			if (a[i] == q.front()) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}