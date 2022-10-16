#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using namespace std;

int n, use[5001], mat[5001][5001], prv[5001], c[5001], st;
std::vector<int> v;

int dfs(int k)
{
	use[k] = 1;
	c[k] = 1;
	v.push_back(k);

	for(int i=1;i<=n;i++)
	{
		if(mat[k][i] == 1)
		{
			if(use[i] == 1 && c[i] == 1)
			{
				st = i;
				return 1;
			}

			if(use[i] == 1) 
				continue;

			if(dfs(i))
				return 1;
		}
	}
	c[k] = 0;
	v.pop_back();
	return 0;
}

void cycle()
{
	int ok = 0, in;
	for(int i=0;i<v.size();i++)
	{
		if(v[i] == st)
		{
			in = i;
			i++;
			ok = 1;
		}
		if(!ok) continue;
		if(mat[v[i]][v[in]] == 1)
		{
			cout << v[in] << ' ' << v[i-1] << ' ' << v[i] << '\n';
			return;
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ' ';
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin >> s;
		for(int j=0;j<s.size();j++)
		{
			mat[i][j+1] = s[j]-'0';
		}
	}

	for(int i=1;i<=n;i++)
	{
		//dbg(i);
		if(!use[i])
			if(dfs(i)) 
				break;
	}
	//dbg_v(use, n);
	//dbg_v(v, v.size());
	if(v.size())
		cycle();
	else
		cout << -1 << '\n';
	return 0;

}