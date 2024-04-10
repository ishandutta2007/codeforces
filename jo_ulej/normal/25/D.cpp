#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;

vector<int> dsu;
vector<pair<int, int>> extra_edges;

struct Quadruplet
{
	int val[4];
};

int find_set(int v)
{
	if(dsu[v] == v)
		return dsu[v];

	dsu[v] = find_set(dsu[v]);

	return dsu[v];
}

bool union_sets(int u, int v)
{
	static int rnd = 0;

	u = find_set(u);
	v = find_set(v);

	if(u == v)
		return false;


	if(rnd++ % 2 == 0)
	{
		dsu[u] = v;
	}
	else
	{
		dsu[v] = u;
	}

	return true;
}

int main(int argc, char** argv)
{
	cin >> n;
	dsu.resize(n);

	for(int i = 0; i < n; ++i)
		dsu[i] = i;

	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;

		cin >> u >> v;
		--u;
		--v;

		if(!union_sets(u, v))
		{
			extra_edges.push_back(make_pair(u, v));
		}
	}

	vector<Quadruplet> ans;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if(find_set(i) != find_set(j))
			{
				int u = extra_edges.back().first;
				int v = extra_edges.back().second;
				extra_edges.pop_back();

				Quadruplet q;
				q.val[0] = u + 1;
				q.val[1] = v + 1;
				q.val[2] = i + 1;
				q.val[3] = j + 1;

				ans.push_back(q);

				union_sets(i, j);
			}
		}
	}

	cout << ans.size() << endl;

	for(int i = 0; i < ans.size(); ++i)
	{
		for(int j = 0; j < 4; ++j)
			cout << ans[i].val[j] << " ";

		cout << endl;
	}
	return 0;
}