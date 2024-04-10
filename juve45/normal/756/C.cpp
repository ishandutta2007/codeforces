#include <bits/stdc++.h>
#define DMAX 100009
#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

using namespace std;

int st[4*DMAX], n, ans, op, pos, val, v[DMAX];
int p[4*DMAX];



void lazy(int nod, int l, int r, int x, int y, int val)
{
	if(p[nod] && l!=r)
	p[2*nod] += p[nod], st[2*nod] += p[nod],
	p[2*nod+1] += p[nod], st[2*nod+1] += p[nod], p[nod] = 0,
	st[nod] = max(st[2*nod], st[2*nod+1]);

	if(x<=l && r<=y)
		p[nod] += val, st[nod] += val; //dbg(l), dbg(r), dbg(y);
	else
	{
		int m = (l+r)/2;

		if(x <= m) 
			lazy(2*nod, l, m, x, y, val);
		if(y>m) 
			lazy(2*nod+1, m+1, r, x, y, val);
		st[nod] = max(st[2*nod], st[2*nod+1]);
	}

}


void upd(int nod, int l, int r, int val, int pos)
{
	if(l == r)
		st[nod] += val,
		p[nod] = 0;
	else{
		if(p[nod])
			p[2*nod] += p[nod], st[2*nod] += p[nod],
			p[2*nod+1] += p[nod], st[2*nod+1] += p[nod],
			p[nod] = 0;

		int m = (l+r)/2;
		if(pos<=m) upd(2*nod, l, m, val, pos);
		else upd(2*nod+1, m+1, r, val, pos);
		st[nod] = max(st[2*nod], st[2*nod+1]);
	}
}

int que(int nod, int l, int r, int x, int y)
{

	if(p[nod] && l!=r)
		p[2*nod] += p[nod], st[2*nod] += p[nod],
		p[2*nod+1] += p[nod], st[2*nod+1] += p[nod],
		st[nod] = max(st[2*nod], st[2*nod+1]);
	p[nod] = 0;

	if(x<=l && r<=y)
		return st[nod];

	int m = (l+r)/2, ans1 = 0, ans2 = 0;

	if(x <= m) 
		ans1 = que(2*nod, l, m, x, y);
	if(y>m) 
		ans2 = que(2*nod+1, m+1, r, x, y);

	return max(ans1, ans2);
}

int find(int l, int r)
{
	if(l == r) return l;

	int m = (l+r)/2;
	//dbg(m);
	//dbg(que(1, 1, n, m+1, n));
	if(que(1, 1, n, m+1, n) <= 0 )
		return find(l, m);
	return find(m+1, r);
}

int main()
{

	cin >> n;
	v[n+1] = -1;
	for(int i=1;i<=n;i++)
	{
		cin >> pos >> op;
		
		if(op == 0)
			lazy(1, 1, n, 1, pos, -1);
		else {
			cin >> val;
			v[pos] = val;
			lazy(1, 1, n, 1, pos, 1);
		}
		
		/*
		dbg(que(1, 1, n, 1, n));
		dbg_v(st, n*4);
		dbg_v(p, n*4);
		
		for(int i=1;i<=n;i++)
			cout << que(1, 1, n, i, i) << ' ';
		cout << '\n';
		dbg(que(1, 1, n, 1, n));*/
		//dbg_v(v, n+3);
		if(que(1, 1, n, 1, n) <= 0) 
			ans = n+1;
		else
			ans = find(1, n);
		cout << v[ans] << '\n';
	}

	return 0;
}