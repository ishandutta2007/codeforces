#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 200100
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, N, ans, k, m, q;
string s;
int st[8 * DMAX], lazy[8 * DMAX];
int value[DMAX], pos[2][DMAX];
vector <int> v[DMAX], euler;

void push(int nod, int l, int r)
{
	if(lazy[nod] % 2 == 1)
	{
		lazy[nod] = 0;
		st[nod] = r - l + 1 - st[nod];
		if(l < r)
		{
			lazy[2 * nod]++;
			lazy[2 * nod + 1]++;
		}
	}
}


int val(int nod, int l, int r)
{
	if(lazy[nod] % 2 == 1)
		return r - l + 1 - st[nod];
	return st[nod];
}


void build(int nod, int l, int r)
{
	if(l == r)
	{
		st[nod] = euler[l];
		return;
	}
	else{
		int mid = (l + r) / 2;
		build(2 * nod, l, mid);
		build(2 * nod + 1, mid + 1, r);
		st[nod] = val(2 * nod, l, mid) + val(2 * nod + 1, mid + 1, r);
	}
}

void upd_interv(int nod, int l, int r, int x, int y)
{
	push(nod, l, r);
	if(l == r)
	{
		st[nod] = 1 - st[nod];
		return ;
	}

	int mid = (l + r) / 2;
	if(x <= l && r <= y)
		lazy[nod]++;
	else{
		if(x <= mid) upd_interv(2 * nod, l, mid, x, y);
		if(y > mid) upd_interv(2 * nod + 1, mid + 1, r, x, y);
	}
	// push(nod, l, r);
	
	st[nod] = val(2 * nod, l, mid) + val(2 * nod + 1, mid + 1, r);
}

int que(int nod, int l, int r, int x, int y)
{
	push(nod, l, r);

	if(x <= l && r <= y)
		return st[nod];

	int mid = (l + r) / 2, ans = 0;

	if(x <= mid) ans += que(2 * nod, l, mid, x, y);
	if(y > mid) ans += que(2 * nod + 1, mid + 1, r, x, y);
	return ans;
}

void dfs(int k)
{
	pos[0][k] = euler.size();
	euler.push_back(k);

	for(int i = 0; i < v[k].size(); i++)
		dfs(v[k][i]);

	pos[1][k] = euler.size();
	euler.push_back(k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		cin >> x;
		v[x].push_back(i);
	}

	for(int i = 1; i <= n; i++)
		cin >> value[i];

	dfs(1);
	//dbg_v(euler, euler.size());
	for(int i = 0; i < euler.size(); i++)
		euler[i] = value[euler[i]];
	N = euler.size() - 1;
	//dbg_v(euler, euler.size());
	build(1, 0, N);
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		cin >> s >> x;
		if(s == "get") {
			cout << que(1, 0, N, pos[0][x], pos[1][x]) / 2 << '\n';
		}
		else {
			upd_interv(1, 0, N, pos[0][x], pos[1][x]);
		}
	}

}