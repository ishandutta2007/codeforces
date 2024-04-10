#include <cstdio>
#include <cstring>
#define min(a,b) ((a)<(b)?(a):(b))

struct data
{
	int a, b, c;
	data(int A, int B, int C) : a(A), b(B), c(C) { }
	data() { data(0, 0, 0); }
	void operator+= (const data& oth)
	{
		int x = min(a, oth.b);
		a += oth.a;
		b += oth.b;
		c += oth.c;
		a -= x; b -= x; c += x;
	}
} tr[2097152];

char buf[1048576];
int n;

void query(int at, int lo, int hi, int qlo, int qhi, data& ans)
{
	if (lo == qlo && hi == qhi)
		ans += tr[at];
	else
	{
		int mid = (lo + hi) >> 1;
		if (qhi <= mid)
			query(at<<1, lo, mid, qlo, qhi, ans);
		else if (qlo >= mid)
			query((at<<1)+1, mid, hi, qlo, qhi, ans);
		else
		{
			query(at<<1, lo, mid, qlo, mid, ans);
			query((at<<1)+1, mid, hi, mid, qhi, ans);
		}
	}
}

int main()
{
	scanf("%s", buf);
	n = strlen(buf);
	for (int i = 0;i < n;i++)
		if (buf[i] == '(')
			tr[i+1048576].a = 1;
		else
			tr[i+1048576].b = 1;
	for (int i = n;i < 1048576;i++)
		tr[i+1048576].a = 1;
	for (int i = 1048575;i;i--)
	{
		tr[i] = tr[i<<1];
		tr[i] += tr[(i<<1)+1];
	}
	scanf("%d", &n);
	while (n--)
	{
		int a, b; scanf("%d%d", &a, &b);
		a--;
		data ans(0, 0, 0);
		query(1, 0, 1048576, a, b, ans);
		printf("%d\n", ans.c<<1);
	}
	return 0;
}