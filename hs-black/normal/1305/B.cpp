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

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 1050;
vector<int> v[N];
int vis[N], cnt, n;
char s[N];
int main() {
	scanf ("%s", s + 1);
	n = strlen(s + 1);
	do {
		int i = 1, j = n;
		cnt++;
		while (i < j) {
			for (; i < j; i++) {
				if (vis[i] || s[i] == ')') continue;
				break;
			}
			for (; j > i; j--) {
				if (vis[j] || s[j] == '(') continue;
				break;
			}
			if (j <= i) break;
			vis[j] = vis[i] = 1;
			v[cnt].push_back(i), v[cnt].push_back(j);
		}
		sort(v[cnt].begin(), v[cnt].end());
		if (!v[cnt].size()) break;
	}while (1);
	cnt--;
	cout << cnt << endl;
	for (int i = 1;i <= cnt; i++) {
		printf ("%d\n", (int)v[i].size());
		for (auto j : v[i]) 
			printf ("%d ", j);
		cout << endl;
	}
	return 0;
}