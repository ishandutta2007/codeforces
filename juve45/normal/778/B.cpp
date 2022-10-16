#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok //cerr<<"OK!\n"
#define DMAX 1

using namespace std;

int n, m, off[1002];
string s, t1, t2, eq;
string g, big, small;
//unordered_map <string, string> mp;
string mp[60001];
unordered_map <string, int> mm;
struct operation
{
	int lhs, rhs1, rhs2;
	char op;
};

vector <operation> v;
vector <int> f;

void dbg_map()
{
	for(auto x : mp)
	{
		dbg(x.first + " = " + x.second + "|");
	}
}

inline int calc(int k)
{
	int ans = off[k];

	for(int i = 0; i < v.size(); i++)
	{
		char cc;
		if(v[i].op == 'X')
			cc = '0' + (mp[v[i].rhs1][k] - '0') ^ (mp[v[i].rhs2][k] - '0');
		else if(v[i].op == 'O')
			cc = '0' + (mp[v[i].rhs1][k] - '0') | (mp[v[i].rhs2][k] - '0');
		else 
			cc = '0' + (mp[v[i].rhs1][k] - '0') & (mp[v[i].rhs2][k] - '0');
		mp[v[i].lhs][k] = cc;
		ans += cc - '0';
	}

/*
	for(auto x : v)
	{
		mp[x.lhs].pop_back();
 	}*/
 	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> eq >> t1;

		if(mm[s] == 0) 
			mm[s] = mm.size();

		if(mm[t1] == 0) 
			mm[t1] = mm.size();

		if(t1[0] == '0' || t1[0] == '1')
		{
			mp[mm[s]] = t1;
			f.push_back(mm[s]);
			for(int i=0 ;i< s.size(); i++)
				off[i] += s[i] - '0';
		}
		else
		{
			operation x;
			string op, r;
			cin >> op >> r;
			x.op = op[0];
			x.lhs = mm[s];
			if(mm[r] == 0)
				mm[r] = mm.size();
			x.rhs1 = mm[t1];
			x.rhs2 = mm[r];
			v.push_back(x);
			mp[mm[s]] = string(m, ' ');
		}
	}
	if(mm["?"] == 0)
		mm["?"] = mm.size();
	int h = mm["?"];
	mp[h] = string(m, ' ');

	for(int k = 0; k < m; k++)
	{
		int val0, val1;

		mp[h][k] = '0';
		val0 = calc(k);

		mp[h][k] = '1';
		val1 = calc(k);

		dbg(val0);
		if(val0 > val1)
			big.append("0"), small.append("1");
		else if(val0 == val1)
			big.append("0"), small.append("0");
		else
			big.append("1"), small.append("0");
/*
		for(auto x : v)
		{
			mp[x.lhs].append("x");
		}*/
	}
	cout << small << '\n' << big;
}