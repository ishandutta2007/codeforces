#include <bits/stdc++.h>
using namespace std;

namespace MCMF
{
	static const int INF = 1 << 30;
	const int NODES = 6009;
	const int EDGES = 9100000;
	int nxt[EDGES], ptr[NODES], to[EDGES]; int cap[EDGES], cz[EDGES];
	int pot[NODES], dis[NODES]; int fr[NODES];
	int flo, fee;
	int n, m;
	void init(int N)
	{
		n = N; m = 0;
		for (int i = 0;i < n;i++) ptr[i] = -1;
	}
	void add_edge(int a, int b, int _, int c)
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
		for (int Z = 0;Z < 4;Z++)
		{
			priority_queue<pair<int, int> > pq;
			for (int i = 0;i < n;i++) dis[i] = INF;
			pq.emplace(dis[src] = 0, src);
			while (!pq.empty())
			{
				auto u(pq.top()); pq.pop();
				if (u.first+dis[u.second]) continue;
				for (int v = ptr[u.second];v != -1;v = nxt[v]) if (cap[v] > 0)
				{
					int alt = cz[v]+pot[u.second]-pot[to[v]]-u.first;
					if (alt < dis[to[v]])
					{
						pq.emplace(-(dis[to[v]]=alt), to[v]);
						fr[to[v]] = v;
					}
				}
			}
			if (dis[sink] == INF) return;
			int send = INF;
			for (int at = sink;at != src;at = to[fr[at]^1]) send = min(send, cap[fr[at]]);
			for (int at = sink;at != src;at = to[fr[at]^1]) cap[fr[at]] -= send, cap[fr[at]^1] += send;
			flo += send;
			fee += send*(dis[sink]+pot[sink]-pot[src]);
			for (int i = 0;i < n;i++) pot[i] += dis[i];
		}
	}
};

int n, arr[3005];

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", arr+i);
	MCMF::init(n*2+2);
	for (int i = 0;i < n;i++) for (int j = i+1;j < n;j++) if (abs(arr[i]-arr[j]) == 1 || abs(arr[i]-arr[j])%7 == 0)
		MCMF::add_edge(i*2+1, j*2, 1, -1);
	for (int i = 0;i < n;i++)
	{
		MCMF::add_edge(n*2, i*2, 1, 0);
		MCMF::add_edge(i*2+1, n*2+1, 1, -1);
		MCMF::add_edge(i*2, i*2+1, 1, 0);
	}
	MCMF::calc(n*2, n*2+1);
	printf("%d\n", -MCMF::fee);
	return 0;
}