#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
#define int long long
using namespace std;
int N;
class stree
{
private:
	int tree[1 << 19];
	int lazy[1 << 19];
	
public:
	int N, treeN;
	stree()
	{
		memset(tree, 10, sizeof(tree));
	}
	int gettreeN()
	{
		return treeN;
	}

	void setNtreeN(int newN)
	{
		N = newN;
		for (treeN = 1; treeN < N; treeN *= 2);
	}
	void set(vector<int>val)
	{
		int i;
		for (i = 0; i < val.size(); i++)
		{
			tree[i + treeN] = val[i];
		}
		for (i = treeN - 1; i; i--)
		{
			
			tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
		}
	}
	void ul(int i)
	{
		tree[i] += lazy[i];
		if (i < treeN)
		{
			lazy[2 * i] += lazy[i];
			lazy[2 * i + 1] += lazy[i];
		}
		lazy[i] = 0;
	}
	int update(int qstart, int qend, int start, int end, int ind, int v)
	{
		ul(ind);
		if (start > qend || qstart > end)
			return 1LL << 30;
		if (start >= qstart && end <= qend)
		{
			tree[ind] += v;
			if (ind < treeN)
			{
				lazy[2 * ind] += v;
				lazy[2 * ind + 1]+=v;
			}
			return tree[ind];
		}

		min(update(qstart, qend, start, (start + end) / 2, ind * 2, v), update(qstart, qend, (start + end) / 2 + 1, end, ind * 2 + 1, v));
		return tree[ind] = min(tree[ind * 2], tree[ind * 2 + 1]);
	}
	int gt()
	{
		return tree[1];
	}
};
int a[200100], b[200100];
int reva[200100];
stree t;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> a[i];
		a[i]--;
		reva[a[i]] = i;
	}
	for (i = 0; i < N; i++)
	{
		cin >> b[i];
	}
	vector<int>yee;
	yee.push_back(0);
	t.setNtreeN(N + 1);
	for (i = 0; i < N; i++)
	{
		yee.push_back(yee[i] + b[reva[i]]);
	}
	int ans = 1LL << 60;
	t.set(yee);
	for (i = 0; i < N-1; i++)
	{
		t.update(0, a[i], 0, t.treeN - 1, 1, b[i]);
		t.update(a[i]+1, N, 0, t.treeN - 1, 1, -b[i]);
		ans = min(ans, t.gt());
	}
	cout << ans;
}