#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100100
#define NMAX 1
#define MMAX 1

using namespace std;

int n, a[DMAX];
map<int, int> m;

int mi(int a, int b, int c)
{
	return min(min(a, b), c);
}
int mx(int a, int b, int c)
{
	return max(max(a, b), c);
}

int md(int a, int b, int c)
{
	return 0LL + a + b + c - mi(a, b, c) - mx(a, b, c);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}	
	a[0] = a[1];
	sort(a + 1, a + n + 1);
	int n3 = n/3;
	n3 += n%3;
	int p1 = 0, p2 = 0;
	for(auto p : m)
	{
		if(p.second >= n/3)
		{
			if(p1 == 0) p1 = p.first;
			else p2 = p.first;
		}
	}
	/*
	if(n == 100000 && a[0] == 2)
	{
		cout << p1 << ' ' << p2 << '\n';
		cout << m[1] << ' ' << m[2] << ' ' << m[3] << '\n';
	}*/
	if(p2 == 0 && p1 == 0)
	{
		cout << n/3 << '\n';
		for(int i = 1, j = n/3+1, k = 2*n/3+1; i <= n/3; i++, j++, k++)
		{
			cout << a[k] << ' ' << a[j] << ' ' << a[i] << '\n';
		}
		return 0;
	}
	//dbg(p1, p2);
	if(p2 == 0 && p1 != 0)
	{
		vector <pair<int, pair<int, int> > > ans;
		priority_queue <pair<int, int> > v;
		map <int, int> use;
		for(int i = 1; i <= n; i++)
			if(a[i] != p1 && use[a[i]] == 0) v.push({m[a[i]], a[i]}), use[a[i]]++;
//		dbg_v(v, v.size());
		while(v.size() > 1)
		{
			int x1 = v.top().second;
			v.pop(); 
			m[x1]--;
			int x2 = v.top().second;
			v.pop(); 
			m[x2]--;
			//dbg(m[x1]);
			//dbg(m[x2]);
			if(m[x1] > 0) 
				v.push({m[x1], x1});
			if(m[x2] > 0) 
				v.push({m[x2], x2});
			ans.push_back({mx(p1, x1, x2), {md(p1, x1, x2), mi(p1, x1, x2)}});
			if(ans.size() == n/3) break;	
		}
/*
		for(int i = 0, j = max((int)v.size()-1, 0); a[i] != a[j] && i < j; i++, j--)
		{
			ans.push_back({mx(p1, v[j], v[i]), {md(p1, v[j], v[i]), mi(p1, v[j], v[i])}});
			if(ans.size() == n/3) break;
		}
		*/
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].second.second << '\n';
		}
	}
	if(p2 != 0)
	{
		vector <pair<int, pair<int, int> > > ans;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] != p1 && a[i] != p2)
			{
				ans.push_back({mx(p1, p2, a[i]), {md(p1, p2, a[i]), mi(p1, p2, a[i])}});
				if(ans.size() == n/3) break;
			}
		}
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].second.second << '\n';
		}
	}

}