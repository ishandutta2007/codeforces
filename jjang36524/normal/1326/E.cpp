#include <iostream>
#include <algorithm>
using namespace std;
int fwtree[1 << 20];
int lazy[1 << 20];
int N, treeN;
void ul(int ind)
{
	fwtree[ind] += lazy[ind];
	if (ind < treeN)
	{
		lazy[ind * 2] += lazy[ind];
		lazy[ind * 2 + 1] += lazy[ind];
	}
	lazy[ind] = 0;
}
void upd(int sl, int sr, int ql, int qr, int p, int ind)
{
	ul(ind);
	if (sr < ql || qr < sl)
		return;
	if (sl >= ql && sr <= qr)
	{
		fwtree[ind] += p;
		if (ind < treeN)
		{
			lazy[ind * 2] += p;
			lazy[ind * 2 + 1] += p;
		}
		return;
	}
	upd(sl, (sl + sr) / 2, ql, qr, p, ind * 2);
	upd((sl + sr) / 2 + 1, sr, ql, qr, p, ind * 2 + 1);
	fwtree[ind] = max(fwtree[ind * 2], fwtree[ind * 2 + 1]);
}
int pos[300100];
int bombs[300100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (treeN = 1; treeN < N; treeN *= 2);
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		pos[a] = i;
	}
	int nowans = N;
	upd(0, treeN - 1, 0, pos[N], 1, 1);
	for (i = 0; i < N; i++)
	{
		cout << nowans << ' ';
		int a;
		cin >> a;
		upd(0, treeN - 1, 0, a - 1, -1, 1);
		while (fwtree[1] <= 0&&nowans)
		{
			nowans--;
			upd(0, treeN - 1, 0, pos[nowans], 1, 1);
		}
	}
}