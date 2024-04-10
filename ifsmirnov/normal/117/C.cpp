#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 5010;
#define pb push_back
#define rs random_shuffle

bool e[maxn][maxn];
int anc[maxn];
int col[maxn];
vector<int> path;

int n;
char t[maxn];
void scan()
{
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%s", t);
		forn(j, n)
			if (t[j] == '1')
				e[i][j] = 1;
	}
}

bool fv, fp;
int root;
void dfs (int v)
{
	col[v] = 1;
	forn(i, n)
	{
		if (e[v][i])
		{
			if (col[i] == 0)
				anc[i] = v, dfs(i);
			else if (col[i] == 1)
			{
				fp = 1, root = i;
			}
			if (fp)
			{
				if (!fv) path.pb(v);
				if (v == root)
					fv = 1;
				break;
			}
		}
	}
	col[v] = 2;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scan();
	
	forn(i, n)
	{
		if (col[i] == 0)
			dfs(i);
		if (fp)
			break;
	}
	if (path.empty())
	{
		cout << "-1";
		return 0;
	}
	else
	{
		while (1)
		{
			//cout << path.front() << " " << path[path.size()-2] << endl;
			if (!e[path.front()][path[path.size()-2]])
			{
				cout << path.front()+1 << " " << path.back()+1 << " " << path[path.size()-2]+1;
				return 0;
			}
			else
				path.pop_back();
		}
	}
	return 0;
}