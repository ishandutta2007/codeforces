#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
class stree
{
private:
	int tree[1 << 18];
	int N, treeN;
public:
	stree()
	{
		memset(tree, 0, sizeof(tree));
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
	void set(vector<int>val, int op)
	{
		int i;
		for (i = 0; i < val.size(); i++)
		{
			tree[i + treeN] = val[i];
		}
		for (i = treeN - 1; i; i--)
		{
			if (op)
			{
				tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
			}
			else
			{
				tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
			}
		}
	}
	int res(int qstart, int qend, int start, int end, int ind, int op)
	{
		if (start > qend || qstart > end)
			return op ? (-(1LL<<60)) : 1LL << 60;
		if (start >= qstart && end <= qend)
			return tree[ind];
		if (op)
		{
			return max(res(qstart, qend, start, (start + end) / 2, ind * 2, op), res(qstart, qend, (start + end) / 2 + 1, end, ind * 2 + 1, op));
		}
		else
		{
			return min(res(qstart, qend, start, (start + end) / 2, ind * 2, op), res(qstart, qend, (start + end) / 2 + 1, end, ind * 2 + 1, op));
		}
	}
}x,y;
int arr[100100];
signed main()
{
	int N, Q;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> Q;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	x.setNtreeN(N + 1);
	y.setNtreeN(N + 1);
	vector<int>psum;
	psum.push_back(0);
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		psum.push_back(psum.back() - arr[i] + a);
	}
	x.set(psum,1);
	y.set(psum, 0);
	int treeN = x.gettreeN();
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		if (psum[a] != psum[b])
		{
			cout << -1 << '\n';
		}
		else
		{
			int ma = x.res(a, b, 0, treeN - 1, 1, 1);
			int mi = y.res(a, b, 0, treeN - 1, 1, 0);
			if (mi < psum[a])
				cout << -1 << '\n';
			else
				cout << ma - psum[a] << '\n';
		}
	}
}