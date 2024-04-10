#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace MCMF
{
	static const ll INF = 1ll << 62;
	const int NODES = 4500;
	const int EDGES = 20000;
	int nxt[EDGES], ptr[NODES], to[EDGES]; ll cap[EDGES], cz[EDGES];
	ll pot[NODES], dis[NODES]; int fr[NODES];
	ll flo, fee;
	int n, m;
	void init(int N)
	{
		n = N; m = 0;
		for (int i = 0;i < n;i++) ptr[i] = -1;
	}
	void add_edge(int a, int b, ll _, ll c)
	{
		nxt[m] = ptr[a]; ptr[a] = m; to[m] = b; cap[m] = _; cz[m] =  c; m++;
		nxt[m] = ptr[b]; ptr[b] = m; to[m] = a; cap[m] = 0; cz[m] = -c; m++;
	}
	void calc(int src, int sink)
	{
		for (int i = 0;i < n;i++) pot[i] = 0;
		for (bool changed = true;changed;)
		{
			changed = false;
			for (int i = 0;i < n;i++) for (int j = ptr[i];j != -1;j = nxt[j]) if (cap[j] > 0 && pot[i]+cz[j] < pot[to[j]])
				pot[to[j]] = pot[i]+cz[j], changed = true;
		}
		while (true)
		{
			priority_queue<pair<ll, int> > pq;
			for (int i = 0;i < n;i++) dis[i] = INF;
			pq.emplace(dis[src] = 0, src);
			while (!pq.empty())
			{
				auto u(pq.top()); pq.pop();
				if (u.first+dis[u.second]) continue;
				for (int v = ptr[u.second];v != -1;v = nxt[v]) if (cap[v] > 0)
				{
					ll alt = cz[v]+pot[u.second]-pot[to[v]]-u.first;
					if (alt < dis[to[v]])
					{
						pq.emplace(-(dis[to[v]]=alt), to[v]);
						fr[to[v]] = v;
					}
				}
			}
			if (dis[sink] == INF) return;
			ll send = INF;
			for (int at = sink;at != src;at = to[fr[at]^1]) send = min(send, cap[fr[at]]);
			for (int at = sink;at != src;at = to[fr[at]^1]) cap[fr[at]] -= send, cap[fr[at]^1] += send;
			flo += send;
			fee += send*(dis[sink]+pot[sink]-pot[src]);
			for (int i = 0;i < n;i++) pot[i] += dis[i];
		}
	}
};

int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	MCMF::init(2*n+2);
	for (int i = 1;i <= n;i++)
	{
		int c; scanf("%d", &c);
		MCMF::add_edge(i, n+i, 1, c);
	}
	for (int i = 1;i <= n;i++)
	{
		int c; scanf("%d", &c);
		MCMF::add_edge(n+i, n+n+1, 1, c);
	}
	for (int i = 2;i <= n;i++)
	{
		MCMF::add_edge(i-1, i, k, 0);
		MCMF::add_edge(n+i-1, n+i, k, 0);
	}
	MCMF::add_edge(0, 1, k, 0);
	MCMF::calc(0, n+n+1);
	printf("%lld\n", MCMF::fee);
	return 0;
}