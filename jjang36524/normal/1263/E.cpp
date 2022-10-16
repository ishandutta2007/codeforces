#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int stree[1 << 22];
int lazy[1 << 22];
int treeN;
using namespace std;
inline void update_lazy(int ind, int s, int e)
{
	stree[ind] += lazy[ind];
	if (ind < treeN)
	{
		lazy[ind * 2] += lazy[ind];
		lazy[ind * 2 + 1] += lazy[ind];
	}
	lazy[ind] = 0;
}
void update(int sstart, int send, int s, int e, int ind, int plu)
{
	update_lazy(ind, sstart, send);
	if (sstart > e || send < s)
		return;
	if (sstart >= s && send <= e)
	{
		stree[ind] += plu;
		if (sstart != send)
		{
			lazy[ind * 2] += plu;
			lazy[ind * 2 + 1] += plu;
		}
		return;
	}
	update(sstart, (sstart + send) / 2, s, e, ind * 2, plu);
	update((sstart + send) / 2 + 1, send, s, e, ind * 2 + 1, plu);
	stree[ind] = min(stree[ind * 2], stree[ind * 2 + 1]);
}
using namespace std;
int streeb[1 << 22];
int lazyb[1 << 22];
using namespace std;
void update_lazyb(int ind, int s, int e)
{
	streeb[ind] += lazyb[ind];
	if (ind < treeN)
	{
		lazyb[ind * 2] += lazyb[ind];
		lazyb[ind * 2 + 1] += lazyb[ind];
	}
	lazyb[ind] = 0;
}
void updateb(int sstart, int send, int s, int e, int ind, int plu)
{
	update_lazyb(ind, sstart, send);
	if (sstart > e || send < s)
		return;
	if (sstart >= s && send <= e)
	{
		streeb[ind] += plu;
		if (sstart != send)
		{
			lazyb[ind * 2] += plu;
			lazyb[ind * 2 + 1] += plu;
		}
		return;
	}
	updateb(sstart, (sstart + send) / 2, s, e, ind * 2, plu);
	updateb((sstart + send) / 2 + 1, send, s, e, ind * 2 + 1, plu);
	streeb[ind] = max(streeb[ind * 2], streeb[ind * 2 + 1]);
}
char ar[1200100];
int totsum;
int N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int oldN = N;
	int i;
	for (treeN = 1; treeN < N; treeN *= 2);
	int curpos = 0;
	int lrsum = 0;
	while (N--)
	{
		int diff = 0;
		char c;
		cin >> c;
		if (c == 'L')
			curpos = max(0, curpos - 1);
		else if (c == 'R')
		{
			curpos++;
		}
		else 
		{
			if (c == '(')
				diff++;
			if (c == ')')
				diff--;
			if (ar[curpos] == ')')
				diff++;
			if (ar[curpos] == '(')
				diff--;
			if (diff)
			{
				update(0, treeN - 1, curpos, oldN - 1, 1, diff);
				updateb(0, treeN - 1, curpos, oldN - 1, 1, diff);
			}
			ar[curpos] = c;
		}
		lrsum += diff;
		if (lrsum || stree[1] < 0)
		{
			cout << -1 << ' ';
		}
		else
		{
			cout << streeb[1] << ' ';
		}
	}
}