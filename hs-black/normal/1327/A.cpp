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

//const int N = 
ll T, n, m, k;
//int f[N], a[N];

int main() {
	read(T);
	while (T--) {
		read(n), read(k); k = k * k;
		if ((n & 1) != (k & 1) || k > n) puts("NO");
		else puts("YES"); 
	}
	return 0;
}