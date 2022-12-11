#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
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
int n;
struct node {
	int a, t;
}p[N];

bool cmp(node i, node j) {
	return i.a < j.a;
}

priority_queue<int> s;

ll ans;
int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(p[i].a);
	for (int j = 1;j <= n; j++) read(p[j].t);
	sort(p + 1, p + n + 1, cmp);
	ll now = 0, sum = 0;
	p[n+1].a = 0x7fffffff;
	for (int i = 1;i <= n; i++) {
		s.push(p[i].t), sum += p[i].t;
		now = p[i].a;
		while (s.size() && now < p[i+1].a) {
			int tp = s.top(); s.pop();
			sum -= tp; ans += sum, now++;
		}
	}
	cout << ans << endl;
	return 0;
}