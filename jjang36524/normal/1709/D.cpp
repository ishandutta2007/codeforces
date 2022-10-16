#include <bits/stdc++.h>
using namespace std;
class stree
{
private:
	int tree[1 << 20];
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
	void set(vector<int>val)
	{
		int i;
		for (i = 0; i < val.size(); i++)
		{
			tree[i + treeN] = val[i];
		}
		for (i = treeN - 1; i; i--)
		{
			tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
		}
	}
	int res(int qstart, int qend, int start, int end, int ind)
	{
		if (start > qend || qstart > end)
			return 0;
		if (start >= qstart && end <= qend)
			return tree[ind];
		return max(res(qstart, qend, start, (start + end) / 2, ind * 2), res(qstart, qend, (start + end) / 2 + 1, end, ind * 2 + 1));
	}
};
stree ma;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	ma.setNtreeN(M);
	vector<int>x;
	int i;
	for (i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		x.push_back(a);
	}
	ma.set(x);
	int Q;
	cin >> Q;
	while (Q--)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if (b > d)
		{
			swap(a, c);
			swap(b, d);
		}
		if (abs(a - c) % e || abs(b - d) % e)
		{
			cout << "NO";
		}
		else
		{
			int r = N / e * e + a % e;
			if (r > N)
			{
				r -= e;
			}
			if (ma.res(b - 1, d - 1, 0, ma.gettreeN() - 1, 1) < r)
			{
				cout << "YES";
			}
			else
			{
				cout << "NO";
			}
		}
		cout << '\n';
	}
}