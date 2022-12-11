#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
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

const int N = 200050;
int p[N], n, m; 
ll sum, l[N];
int main() {
	read(n), read(m);
	for (int i = 1;i <= m; i++) read(l[i]), sum += l[i];
	if (sum < n) return puts("-1");
	for (int i = 1;i <= m; i++)
		if (i + l[i] - 1 > n) return puts("-1");
	int x = n;
	for (int i = m;i >= 1; i--) {
		if (x > i + l[i] - 1) x -= l[i], p[i] = x + 1;
		else p[i] = i, x = i - 1;
	}
	for (int i = 1;i <= m; i++) printf ("%d ", p[i]);
	return 0;
}