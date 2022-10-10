#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long
#define MOD 1000000007

ll res;
int N, K;
int A[200201];
vector<pair<int, int> > g[200201];
int sz[200201];
bool vis[200201];
ll fenC[200201], fenH[200201], fenCC[200201], fenHH[200201];

ll Sum(ll fen[], int idx)
{
	idx++; // 1-based

	idx = min(idx, N); //   .    
	if (idx < 0) return 0LL; //   .

	ll ret = 0;
	while(idx)
	{
		ret += fen[idx], ret %= MOD;
		idx &= idx-1;
	}
	return ret;
}

void Add(ll fen[], int idx, ll val)
{
	idx++; // 1-based
	while(idx <= N)
	{
		fen[idx] += val, fen[idx] %= MOD; // cnt    
		idx += idx & -idx;
	}
}

void Del(ll fen[], int idx)
{
	idx++; // 1-based
	while(idx <= N)
	{
		fen[idx] = 0;
		idx += idx & -idx;
	}
}

void DFS(int n, int prev)
{
	sz[n] = 1;
	for(auto [next,cost] : g[n])
	{
		if (next == prev || vis[next]) continue;
		DFS(next, n);
		sz[n] += sz[next];
	}
}

int Centroid(int n, int prev, const int V)
{
	for(auto [next,cost] : g[n])
	{
		if (next == prev || vis[next]) continue;
		if (sz[next]*2 > V)
			return Centroid(next, n, V);
	}
	return n;
}

vector<pair<int, ll> > v;
void DFS2(int n, int prev, int last, int d, ll h, int root)
{
	// cout << n << " : " << d << " " << h << "\n";

	// - !!
	if (d <= K)
	{
		res += h + A[root], res %= MOD;
		// cout << root << " " << n << " : " << h + A[root] << endl;
	}
	v.push_back({d, h % MOD}); // %= MOD ..

	for(auto [next,cost] : g[n])
	{
		if (next == prev || vis[next]) continue;
		DFS2(next, n, cost, d + (cost != last), h + A[next], root);
	}
}

void dnc(int n)
{
	vis[n] = true;
	// cout << "dnc(" << n << ")" << endl;

	// (u,u) valid.
	res += A[n], res %= MOD;

	// sum_{Dj <= K-Di} (Hj), (1)
	vector<int> del;
	for(auto [next,cost] : g[n])
	{
		if (vis[next]) continue;
		if (cost == 1) continue;

		v.clear();
		DFS2(next, n, cost, 0, A[next], n);

		for(auto [d,h] : v)
		{
			// 1. 0 <=> 0
			ll cnt = Sum(fenC, K-d), val = Sum(fenH, K-d);
			res += (h + A[n]) * cnt + val, res %= MOD;
		}

		for(auto [d,h] : v) //  :    ..
		{
			Add(fenC, d, 1), Add(fenH, d, h);
			del.push_back(d);
		}
	}
	for(auto [next,cost] : g[n])
	{
		if (vis[next]) continue;
		if (cost == 0) continue;

		v.clear();
		DFS2(next, n, cost, 0, A[next], n);

		for(auto [d,h] : v)
		{
			// 2. 1 <=> 1
			ll cnt = Sum(fenCC, K-d), val = Sum(fenHH, K-d);
			res += (h + A[n]) * cnt + val, res %= MOD;
			
			// 3. 0 <=> 1
			cnt = Sum(fenC, K-d-1), val = Sum(fenH, K-d-1); // K-d-1 
			res += (h + A[n]) * cnt + val, res %= MOD;
		}

		for(auto [d,h] : v) //
		{
			Add(fenCC, d, 1), Add(fenHH, d, h);
			del.push_back(d);
		}
	}

	//  : memset   ..
	for(int d : del)
	{
		Del(fenC, d);
		Del(fenH, d);
		Del(fenCC, d);
		Del(fenHH, d);
	}

	for(auto [next,cost] : g[n])
	{
		if (vis[next]) continue;
		DFS(next, n);
		dnc(Centroid(next, n, sz[next]));
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> K;
	for(int i=1; i<=N; i++)
		cin >> A[i];
	for(int i=0; i<N-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	DFS(1, 0);
	dnc(Centroid(1, 0, N));

	res %= MOD; res += MOD; res %= MOD;
	cout << res << "\n";
	return 0;
}