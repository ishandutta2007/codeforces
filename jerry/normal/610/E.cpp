#include <bits/stdc++.h>
using namespace std;

struct node
{
	int lz, fr, bk;
	int ad[10][10];
	void operator+= (const node& oth)
	{
		for (int i = 0;i < 10;i++) for (int j = 0;j < 10;j++) ad[i][j] += oth.ad[i][j];
		if (bk != -1) ad[bk][oth.fr]++;
		bk = oth.bk;
	}
} tr[524288], res;

char buf[262144];
int wh[16];
int n, m, k;

void query(int at, int lo, int hi, int rlo, int rhi)
{
	if (lo == rlo && hi == rhi)
		res += tr[at];
	else
	{
		int mid = (lo+hi) >> 1;
		if (rhi <= mid) query(at*2, lo, mid, rlo, rhi);
		else if (rlo >= mid) query(at*2+1, mid, hi, rlo, rhi);
		else
		{
			query(at*2, lo, mid, rlo, mid);
			query(at*2+1, mid, hi, mid, rhi);
		}
	}
}

void upd(int at, int lo, int hi, int rlo, int rhi, int c)
{
	if (lo == rlo && hi == rhi)
	{
		tr[at].lz = c;
		tr[at].fr = c;
		tr[at].bk = c;
		for (int i = 0;i < 10;i++) for (int j = 0;j < 10;j++) tr[at].ad[i][j] = 0;
		tr[at].ad[c][c] = hi-lo-1;
	} else
	{
		int mid = (lo+hi) >> 1;
		if (tr[at].lz != -1)
		{
			upd(at*2, lo, mid, lo, mid, tr[at].lz);
			upd(at*2+1, mid, hi, mid, hi, tr[at].lz);
		}
		if (rhi <= mid) upd(at*2, lo, mid, rlo, rhi, c);
		else if (rlo >= mid) upd(at*2+1, mid, hi, rlo, rhi, c);
		else upd(at*2, lo, mid, rlo, mid, c), upd(at*2+1, mid, hi, mid, rhi, c);
		tr[at] = tr[at*2];
		tr[at] += tr[at*2+1];
		tr[at].lz = -1;
	}
}

int main()
{
	scanf("%d%d%d%s", &n, &m, &k, buf);
	for (int i = 0;i < n;i++) tr[i+262144].fr = tr[i+262144].bk = buf[i]-'a';
	for (int i = 262143;i;i--)
	{
		tr[i] = tr[i*2];
		tr[i] += tr[i*2+1];
	}
	for (int i = 0;i < 524288;i++) tr[i].lz = -1;
	while (m--)
	{
		int typ; scanf("%d", &typ);
		if (typ == 1)
		{
			int l, r; char c;
			scanf("%d%d %c", &l, &r, &c);
			upd(1, 0, 262144, l-1, r, c-'a');
		} else
		{
			scanf("%s", buf);
			for (int i = 0;i < k;i++)
				wh[buf[i]-'a'] = i;
			int ans = 1;
			res.bk = -1;
			for (int i = 0;i < k;i++) for (int j = 0;j < k;j++)
				res.ad[i][j] = 0;
			query(1, 0, 262144, 0, n);
			for (int i = 0;i < k;i++) for (int j = 0;j < k;j++) if (wh[i] >= wh[j])
				ans += res.ad[i][j];
			printf("%d\n", ans);
		}
	}
	return 0;
}