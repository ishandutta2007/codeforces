#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 200009

using namespace std;


long long r[DMAX][7];
long long r2[DMAX][7];
vector <long long> v[DMAX];
long long n, m, k, ans, c[DMAX], a, b, use[DMAX], c2[DMAX];

void dfs2(long long nd, long long t)
{
	if(t>0)
	{
		ans += c[t] + r[t][0];// adaug la raspunsul general costul sa ma duc la fratii mei.
		ans += c2[t] + r2[t][0];// adaug la raspunsul general costul sa ma duc la fratii mei.

		//chestie
		for(long long l = 1;l<=k;l++)
			r2[nd][l%k] += r[t][l-1] + r2[t][l-1]; // actualizez ultimii pasi facuti de acest nod. 

		c2[nd] += c2[t] + r[t][0] + r2[t][0] + c[t];// ca sa ajung la toti descendentii din fiul curent.
	}
	//dbg(nd);
	for(long long i=0;i<v[nd].size();i++)
	{
		if(v[nd][i] == t) continue;


		dfs2(v[nd][i], nd);
		//if(nd == 1) dbg(v[nd][i]);

		c[nd] += c[ v[nd][i] ] + r[ v[nd][i] ][0];// ca sa ajung la toti descendentii din fiul curent.

		for(long long l = 1;l<=k;l++)
			r[nd][l%k] += r[v[nd][i]][l-1]; // actualizez ultimii pasi facuti de acest nod. 

		c[nd]++; // ca sa ajung la fiu
		r[nd][0]++; // inca un pas ca sa ajung la fiul curent;
	}

}

void dfs(long long nd, long long t)
{
	if(t>0)
	{
		ans += c[t] + r[t][0];// adaug la raspunsul general costul sa ma duc la fratii mei.
		ans += c2[t] + r2[t][0];// adaug la raspunsul general costul sa ma duc la fratii mei.

		//chestie
		for(long long l = 1;l<=k;l++)
			r2[nd][l%k] += r[t][l-1] + r2[t][l-1]; // actualizez ultimii pasi facuti de acest nod. 

		c2[nd] += c2[t] + r[t][0] + r2[t][0] + c[t];// ca sa ajung la toti descendentii din fiul curent.
	}
	//dbg(nd);
	for(long long i=0;i<v[nd].size();i++)
	{
		if(v[nd][i] == t) continue;


		dfs(v[nd][i], nd);
		//if(nd == 1) dbg(v[nd][i]);

		c[nd] += c[ v[nd][i] ] + r[ v[nd][i] ][0];// ca sa ajung la toti descendentii din fiul curent.

		for(long long l = 1;l<=k;l++)
			r[nd][l%k] += r[v[nd][i]][l-1]; // actualizez ultimii pasi facuti de acest nod. 

		c[nd]++; // ca sa ajung la fiu
		r[nd][1]++; // inca un pas ca sa ajung la fiul curent;
	}

}


int main()
{
	cin >> n >> k;

	for(long long i=1;i<n;i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(k==1)
	{
		dfs2(1, -1);

		for(long long i=1;i<=n;i++)
			ans += c[i];

		cout << ans << '\n';
		return 0;
	}
	dfs(1, -1);
	//dbg(ans);
	for(long long i=1;i<=n;i++)
		ans += c[i];

	cout << ans << '\n';

/*
	dbg_v(r[1], k);
	dbg_v(r[2], k);
	dbg_v(r[3], k);
	dbg_v(r[4], k);
	*/


}