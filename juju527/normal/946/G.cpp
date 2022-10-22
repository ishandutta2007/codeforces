#include <bits/stdc++.h>

using namespace std;
const int N = 6e5;

int n, m(0), cnt(0);
int a[N], b[N], c[N], f[N][2];
map < int, int > tag;

int read(void)
{
	int s = 0, w = 0; char c = getchar();
	while (c < '0' || c > '9') w |= c == '-', c = getchar();
	while (c >= '0' && c <= '9') s = s*10+c-48, c = getchar();
	return w ? -s : s;
}

void input(void)
{
	n = read();
	for (int i=1;i<=n;++i) {
		a[i] = read() - i;
		b[i] = a[i] + 1;
		c[++ m] = a[i], c[++ m] = b[i]; 
	}	
	sort(c + 1, c + m + 1);
	for (int i=1;i<=m;++i)
	{
		if (c[i] != c[i-1]) tag[c[i]] = ++ cnt;
		else if (i == 1) tag[c[i]] = ++ cnt;
	}
	for (int i=1;i<=m;++i) {
		a[i] = tag[a[i]];
		b[i] = tag[b[i]];
	}
	//for (int i=1;i<=n;++i) cout<<a[i]<<' ';cout<<endl;
	//for (int i=1;i<=n;++i) cout<<b[i]<<' ';cout<<endl;
}

struct BIT
{
	#define lowbit(i) (i & -i)
	int S[N * 10] = {};
	void add(int x, int v) {
		for (int i=x;i<=cnt;i+=lowbit(i))
			S[i] = max(S[i], v);
		return;
	}
	int ask(int x) {
		int res = 0;
		for (int i=x;i>=1;i-=lowbit(i))
			res = max(res, S[i]);
		return res;
	}
}  tree1, tree2, tree3;

void work(void)
{
	int res = 0;
	for (int i=1;i<=n;++i)
	{
		int val1 = tree1.ask(a[i]);
		int val2 = tree2.ask(a[i]);
		int val3 = tree3.ask(b[i]);
		f[i][0] = val1 + 1;
		if (val2 > 0) f[i][1] = val2 + 1;
		if (i > 2) f[i][1] = max(f[i][1], val3 + 1);
		tree1.add(a[i], f[i][0]);
		tree2.add(a[i], f[i][1]);
		if (i > 1) tree3.add(a[i-1], f[i-1][0]);
		res = max(res, max(f[i][0], f[i][1]));
	}
	cout << max(n - 1 - res, 0) << endl;
	return;
}

int main(void)
{
	input();
	work();
	return 0;
}