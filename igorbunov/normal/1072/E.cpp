#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
vector <int> x, y, z;
namespace force {
	const int MAXN = 13;
	unordered_map <bitset <MAXN>, bitset <MAXN> > from;
	bitset <MAXN> q[1 << MAXN], dest;
	void work(int *a, int n, int delta) {
		dest.reset();
		for (int i = 1; i <= n; i++)
			dest[i] = a[i];
		if (dest == 0) return;
		int l = 0, r = 0;
		q[0] = 0, from[0] = 0;
		while (l <= r) {
			bitset <MAXN> now = q[l++];
			for (int i = 1; i <= n; i++)
			for (int j = i + 2; j <= n; j += 2) {
				int k = (i + j) / 2;
				bitset <MAXN> tmp = now;
				tmp.flip(i), tmp.flip(j), tmp.flip(k);
				if (from.count(tmp) == 0) {
					from[tmp] = now;
					q[++r] = tmp;
					if (tmp == dest) {
						bitset <MAXN> pos = tmp;
						while (pos != 0) {
							bitset <MAXN> tnp = pos ^ from[pos];
							int val = 0;
							x.push_back((val = tnp._Find_first()) + delta);
							y.push_back((val = tnp._Find_next(val)) + delta);
							z.push_back((val = tnp._Find_next(val)) + delta);
							pos = from[pos];
						}
						return;
					}
				}
			}
		}
		printf("NO\n");
		exit(0);
	}
}
int n, a[MAXN];
int main() {
	//freopen("problem.in", "r", stdin);
	//freopen("problem.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	if (n <= 12) force :: work(a, n, 0);
	else {
		int head = 1, back = n;
		while (back - head >= 12 && a[head] == 0) head++;
		while (back - head >= 12 && a[back] == 0) back--;
		while (back - head >= 12) {
			if (a[head] + a[head + 1] + a[head + 2] == 3) {
				a[head] = a[head + 1] = a[head + 2] = 0;
				x.push_back(head);
				y.push_back(head + 1);
				z.push_back(head + 2);
			} else if (a[back] + a[back - 1] + a[back - 2] == 3) {
				a[back] = a[back - 1] = a[back - 2] = 0;
				x.push_back(back);
				y.push_back(back - 1);
				z.push_back(back - 2);
			} else if ((head + back) % 2 == 0) {
				a[head] = a[back] = 0;
				int mid = (head + back) / 2;
				a[mid] = 1 - a[mid];
				x.push_back(head);
				y.push_back(back);
				z.push_back(mid);
			} else if (a[head + 1] == 1) {
				a[head + 1] = a[back] = 0;
				int mid = (head + 1 + back) / 2;
				a[mid] = 1 - a[mid];
				x.push_back(head + 1);
				y.push_back(back);
				z.push_back(mid);
			} else if (a[back - 1] == 1) {
				a[head] = a[back - 1] = 0;
				int mid = (head + back - 1) / 2;
				a[mid] = 1 - a[mid];
				x.push_back(head);
				y.push_back(back - 1);
				z.push_back(mid);
			} else if (a[head + 2] == 1) {
				a[head + 2] = a[head] = 0;
				a[head + 4] = 1 - a[head + 4];
				x.push_back(head);
				y.push_back(head + 2);
				z.push_back(head + 4);
			} else if (a[back - 2] == 1) {
				a[back - 2] = a[back] = 0;
				a[back - 4] = 1 - a[back - 4];
				x.push_back(back);
				y.push_back(back - 2);
				z.push_back(back - 4);
			} else {
				int tmp = back - 3;
				a[head] = 1 - a[head];
				a[tmp] = 1 - a[tmp];
				int mid = (head + tmp) / 2;
				a[mid] = 1 - a[mid];
				x.push_back(head);
				y.push_back(tmp);
				z.push_back(mid);
			}
			while (back - head >= 12 && a[head] == 0) head++;
			while (back - head >= 12 && a[back] == 0) back--;
		}
		force :: work(a + head - 1, back - head + 1, head - 1);
	}
	printf("YES\n");
	assert((int) x.size() <= n / 3 + 12);
	writeln(x.size());
	for (unsigned i = 0; i < x.size(); i++)
		printf("%d %d %d\n", x[i], y[i], z[i]);
	return 0;

}