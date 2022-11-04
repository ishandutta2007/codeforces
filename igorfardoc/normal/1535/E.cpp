#include<bits/stdc++.h>
#define LOG 20
using namespace std;
typedef long long ll;
int q;
vector<vector<int> > g;
vector<int> a, c;
vector<vector<int> > prev1;
vector<bool> used;

void fill(int v, int p)
{
	prev1[v][0] = p;
	for(int i = 1; i < LOG; i++)
	{
		prev1[v][i] = prev1[prev1[v][i - 1]][i - 1];
	}
}

pair<ll, ll> get(int v, int w)
{
	if(used[v])
	{
		return {0, 0};
	}
	if(v == 0)
	{
		if(w <= a[0])
		{
			a[0] -= w;
			return {w, (ll)w * c[0]};
		}
		else
		{
			pair<ll, ll> res = {a[0], (ll)a[0] * c[0]};
			a[0] = 0;
			used[0] = true;
			return res;
		}
	}
	ll fir = 0;
	ll sec = 0;
	for(int i = LOG - 1; i >= 0; i--)
	{
		auto p = get(prev1[v][i], w - fir);
		fir += p.first;
		sec += p.second;
		if(fir == w)
		{
			return {fir, sec};
		}
	}
	if(w <= fir + a[v])
		{
			a[v] -= (w - fir);
			return {w, sec + (ll)(w - fir) * c[v]};
		}
		else
		{
			pair<ll, ll> res = {a[v] + fir, sec + (ll)a[v] * c[v]};
			a[v] = 0;
			used[v] = true;
			return res;
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> q;
    prev1.assign(q + 1, vector<int>(LOG, 0));
    g.resize(q + 1);
    a.resize(q + 1);
    c.resize(q + 1);
    used.assign(q + 1, false);
    cin >> a[0] >> c[0];
    fill(0, 0);
    for(int i = 1; i <= q; i++)
    {
    	int mod;
    	cin >> mod;
    	if(mod == 1)
    	{
    		int p;
    		cin >> p >> a[i] >> c[i];
    		g[p].push_back(i);
    		fill(i, p);
    	}
    	else
    	{
    		int v, w;
    		cin >> v >> w;
    		auto res = get(v, w);
    		cout << res.first << ' ' << res.second << endl;
    	}
    }
}