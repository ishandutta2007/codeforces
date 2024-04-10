#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok //cerr<<"OK!\n"
#define DMAX 200100
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, k, m, dag = 1, a, b;
int up[DMAX], c[DMAX], use[DMAX], st[DMAX], ord[DMAX], cnt[DMAX], Q[DMAX], Q2[DMAX], cnt2[DMAX];
string s;
vector<int> v[DMAX], g[DMAX];
set<int> usek;

void dfs(int node)
{
	st[node] = 1;
	use[node] = 1;
	for(auto i : v[node])
	{
		if(st[i])
			dag = 0;
		if(!use[i])
			dfs(i);
	}
	st[node] = 0;
}


void bfsUp()
{
	queue <int> q;

	for(int i = 1; i <= n; i++)
		if(g[i].size() == 0)
			q.push(i), Q2[i] = 1;
		else cnt2[i] = g[i].size();

	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		dbg(node);
		if(c[node] == 0)
			up[node] = k;
		else 
			up[node] = c[node];

		if(c[node] == 0)
			for(auto vec : g[node])
				up[node] = min(up[node], up[vec] - 1);
			

		for(auto vec : v[node])
		{
			cnt2[vec]--;
			if(cnt2[vec] == 0)
				if(!Q2[vec])
					q.push(vec), Q2[vec] = 1;
		}
	}	
	
}

int getNext(int last)
{
	auto it = usek.lower_bound(last);
	if(it != usek.end())
		return *it;
	return k;
}

int del(int last)
{
	if(usek.find(last) != usek.end())
		usek.erase(last);
}

class Compare
{
public:
    bool operator() (int a, int b)
    {
    	return up[a] > up[b];
    	/*
    	if(ord[a] > ord[b])
    		return true;
    	if(ord[a] == ord[b])
    		return up[a] > up[b];
    	return false;
    	*/
    }
};

/*
void dfsLow(int node)
{
	for(auto vec : v[node])
	{

	}
}
*/

void bfsLow()
{
	priority_queue <int, vector<int>, Compare> q;

	for(int i = 1; i <= n; i++)
		if(v[i].size() == 0)
			q.push(i), Q[i] = 1;
		else cnt[i] = v[i].size();

	int last = getNext(0);

	while(!q.empty())
	{

		int node = q.top();
		dbg(node);
		q.pop();

		int low = 0;
		for(auto vec : v[node])
			low = max(low, c[vec]);
		low++;
		dbg(low);

		if(low > up[node])
		{
			cout << "-1";
			exit(0);
		}

		if(c[node] == 0)
		{
			if(low <= last)
			{
				if(last <= up[node])
				{
					c[node] = last;
					del(last);
					last = getNext(last);
				}
				else c[node] = up[node];
			}
			else 
			{
				int last2 = getNext(low);
				c[node] = last2;
				del(last2);
			}
		}

		for(auto vec : g[node])
		{
			cnt[vec]--; 
			if(cnt[vec] == 0)
				if(!Q[vec])
					q.push(vec), Q[vec] = 1;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++)
		usek.insert(i);
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		del(c[i]);
	}

	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b); // a > b
		g[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
		if(!use[i])
			dfs(i);

	if(!dag)
	{
		cout << "-1\n";
		return 0;
	}
	bfsUp();

//	return 0;
	bfsLow();

	dbg_v(c, n + 1);

		
	
	if(!usek.empty())
	{
		cout << -1 <<'\n';
		return 0;
	}
	for(int i = 1; i <= n ; i++)
		cout << c[i] << ' ';
}