#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
#define int long long
int N;
int treeN;
struct tree
{
	
	int stree[1 << 21];
	void update(int n, int c)
	{
		n += treeN;
		stree[n] = c;
		while (n / 2 >= 1)
		{
			n /= 2;
			stree[n] = min(stree[n * 2], stree[n * 2 + 1]);
		}
	}
	int q1(int s, int e, int qs, int qe, int i, int c)
	{
		if (s > qe || qs > e)
			return -2;
		if (stree[i] >= c)
			return -2;
		if (qs >= s && qe <= e)
		{
			if (qs == qe)
				return qs;
			if (stree[i * 2] < c)
				return q1(s, e, qs, (qs + qe) / 2, i * 2, c);
			else
				return q1(s, e, (qs + qe) / 2 + 1, qe, i * 2 + 1, c);
		}
		else
		{
			int fans = q1(s, e, qs, (qs + qe) / 2, i * 2, c);
			if (fans != -2)
				return fans;
			else
				return q1(s, e, (qs + qe) / 2 + 1, qe, i * 2 + 1, c);
		}
	}
}o,e;
int psum[300100];
map<int, vector<int>>ex,ox;
signed main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		ox.clear();
		ex.clear();
		memset(o.stree, -100, N*32);
		memset(e.stree, -100, N*32);
		int N;
		cin >> N;
		for (treeN = 1; treeN < (N + 1) / 2; treeN*=2);
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			psum[i] = a;
			if (i)
				psum[i] -= psum[i - 1];
			if (i % 2)
			{
				o.update(i / 2, psum[i]);
				ox[psum[i]].push_back(i);
			}
			else
			{
				e.update(i / 2, psum[i]);
				ex[psum[i]].push_back(i);
			}
				
			
		}
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			int p;
			if (i)
				p = psum[i - 1];
			else
				p = 0;
			int li = N;
			if (i % 2)
			{
				int ol = i / 2;
				int el = ol+1;
				int of = o.q1(ol, N / 2-1, 0, treeN - 1, 1, -p)*2+1;
				int ef = e.q1(el, (N +1)/ 2-1, 0, treeN - 1, 1, p)*2;
				if (of != -3)
					li = min(li, of);
				if (ef != -4)
					li = min(li, ef);
				ans += lower_bound(ox[-p].begin(), ox[-p].end(), li) - lower_bound(ox[-p].begin(), ox[-p].end(), i);
				ans += lower_bound(ex[p].begin(), ex[p].end(), li) - lower_bound(ex[p].begin(), ex[p].end(), i);
			}
			else
			{
				int ol = i / 2;
				int el = i/2;
				int of = o.q1(ol, N / 2-1, 0, treeN - 1, 1, p)*2+1;
				int ef = e.q1(el, (N + 1) / 2-1, 0, treeN - 1, 1, -p)*2;
				if (of != -3)
					li = min(li, of);
				if (ef != -4)
					li = min(li, ef);
				ans += lower_bound(ox[p].begin(), ox[p].end(), li) - lower_bound(ox[p].begin(), ox[p].end(), i);
				ans += lower_bound(ex[-p].begin(), ex[-p].end(), li) - lower_bound(ex[-p].begin(), ex[-p].end(), i);
			}
		
		}
		cout << ans << '\n';
	}
}