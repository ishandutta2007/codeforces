#include <bits/stdc++.h>
#define N 100005
using namespace std;

template <typename T>

void read(T &a)
{
	T x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	a = x * f;
}

template <typename T>

void write(T x)
{
	if (x < 0) putchar('-'),x = -x;
	if (x < 10) return (void) putchar(x + '0');
	write(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>

void writeln(T x)
{
	write(x);
	putchar('\n');
}

template <typename T>

void writes(T x)
{
	write(x);
	putchar(' ');
}

template <typename T,typename... Args> 

void read(T &maxx,Args &... args)
{
	read(maxx);
	read(args...);
}

template <typename T,typename... Args>

void writeln(T maxx,Args ... args)
{
	writes(maxx);
	writes(args...);
	putchar('\n');
}

const int B = 300;
int n,q,a[N],num,bl[N],vis[N];
std::vector<int> v;

struct Block
{
	int f[B],lazy,flag,cnt,L,R;
	void update()
	{
		flag = 1;
		for (int i = L; i <= R; i++)
		{
			if (bl[i] != bl[a[i]]) f[i - L] = i;
			else f[i - L] = f[a[i] - L],flag = 0;
		}
	}
	void update(int l,int r,int x)
	{
		for (int i = l; i <= r; i++)
			a[i] = i == 1 ? 0 : max(a[i] - x,1);
		update();
	}
	void update(int x)
	{
		if (flag) lazy += x;
		else update(L,R,x);
		lazy = min(lazy, n);
	}
}T[(N - 1) / B + 5];

void update(int l,int r,int x)
{
	if (bl[l] == bl[r])
	{
		T[bl[l]].update(l,r,x);
		return ;
	}
	T[bl[l]].update(l,T[bl[l]].R,x);
	for (int i = bl[l] + 1; i < bl[r]; i++)
		T[i].update(x);
	T[bl[r]].update(T[bl[r]].L,r,x);
	// cout << l << ' ' << r << ' ' << x << endl;
	// cout << '0' << ' ';
	// for (int i = 2; i <= n; i++)
	// 	cout << max(a[i] - T[bl[i]].lazy,1) << ' ';
	// cout << endl;
}

void clear()
{
	for (int i = 0; i < v.size(); i++)
		vis[v[i]] = 0;
	v.clear();
}

int query(int x,int y)
{
	// cout << '0' << ' ';
	// for (int i = 2; i <= n; i++)
	// 	cout << max(a[i] - T[bl[i]].lazy,1) << ' ';
	// cout << endl;
	while (T[bl[x]].f[x - T[bl[x]].L] != T[bl[y]].f[y - T[bl[y]].L])
	{
		if (bl[x] < bl[y]) swap(x,y);
		// cout << x << ' ' << T[bl[x]].f[x - T[bl[x]].L] << endl;
		x = (T[bl[x]].f[x - T[bl[x]].L] == 1) ? 0 : max(a[T[bl[x]].f[x - T[bl[x]].L]] - T[bl[x]].lazy,1);
	}
	int qaq = (T[bl[x]].f[x - T[bl[x]].L] == 1) ? 0 : max(a[T[bl[x]].f[x - T[bl[x]].L]] - T[bl[x]].lazy,1);
	while (x != qaq)
	{
		assert(x != qaq);
		vis[x] = 1;
		v.push_back(x);
		x = (x == 1) ? 0 : max(a[x] - T[bl[x]].lazy,1);
	}
	while (y != qaq)
	{
		if (vis[y]) return clear(),y;
		y = (y == 1) ? 0 : max(a[y] - T[bl[y]].lazy,1);
	}
}

signed main()
{
	read(n,q);
	for (int i = 2; i <= n; i++) read(a[i]);
	num = (n - 1) / B + 1;
	for (int i = 1; i <= num; i++)
	{
		T[i].L = (i - 1) * B + 1;
		T[i].R = min(i * B,n);
		T[i].cnt = i * B - (i - 1) * B;
		T[i].flag = T[i].lazy = 0;
		for (int j = T[i].L; j <= T[i].R; j++)
			bl[j] = i;
	}
	for (int i = 1; i <= num; i++)
		T[i].update();
	while (q--)
	{
		int opt;
		read(opt);
		if (opt == 1)
		{
			int l,r,x;
			read(l,r,x);
			update(l,r,x);
		}
		if (opt == 2)
		{
			int u,v;
			read(u,v);
			writeln(query(u,v));
		}
	}
	// cerr << (double) clock() / CLOCKS_PER_SEC << endl;
	return 0;
}