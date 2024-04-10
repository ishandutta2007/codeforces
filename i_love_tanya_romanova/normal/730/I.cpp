#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>

#include <unordered_map>

using namespace std;

#ifdef LOCAL
#define debug_flag 1
#else
#define debug_flag 0
#endif

template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p)
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<vector<T>>& v)
{

	os << "[" << endl;
	bool first = true;
	for (typename std::vector<vector<T>>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it << endl;
	}
	os << "]" << endl;
	return os;
}

typedef long long int int64;

struct Edge
{
	int v, to, flow, cap, cost;
	Edge() : v(), to(), flow(), cap(), cost() {}
	Edge(int _v, int _to, int _cap, int _cost) :
		v(_v), to(_to), flow(0), cap(_cap), cost(_cost) {}
};

const int N = 3005;
const int V = 2 * N;
const int E = (int)1e6;
const int INF = (int)1e9;

int n, p_cnt, s_cnt;
int a_list[N], b_list[N];

int s, t;

int v_cnt;
vector<int> graph[V];

int e_cnt;
Edge e_list[E];

queue<int> q;
bool in_q[V];
int dist[V];
int par_v[V];
int par_e[V];

void add_edge(int v, int to, int cap, int cost)
{
	e_list[e_cnt] = Edge(v, to, cap, cost);
	graph[v].push_back(e_cnt);
	e_cnt++;

	e_list[e_cnt] = Edge(to, v, 0, -cost);
	graph[to].push_back(e_cnt);
	e_cnt++;
}

void solve()
{
	scanf("%d%d%d", &n, &p_cnt, &s_cnt);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &a_list[i]);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &b_list[i]);

	int pv = n;
	int sv = n + 1;
	s = n + 2;
	t = n + 3;
	v_cnt = t + 1;

	for (int i = 0; i < n; i++)
		add_edge(s, i, 1, 0);

	for (int i = 0; i < n; i++)
	{
		add_edge(i, pv, 1, a_list[i]);
		add_edge(i, sv, 1, b_list[i]);
	}

	add_edge(pv, t, p_cnt, 0);
	add_edge(sv, t, s_cnt, 0);

	int ans_flow = 0;
	int ans_cost = 0;

	while (true)
	{
		fill(dist, dist + v_cnt, -INF);
		dist[s] = 0;
		q.push(s);
		in_q[s] = true;

		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			in_q[v] = false;

			for (int e_id : graph[v])
			{
				int to = e_list[e_id].to;
				int can = e_list[e_id].cap - e_list[e_id].flow;
				int cost = e_list[e_id].cost;
				if (can == 0)
					continue;
				if (dist[to] < dist[v] + cost)
				{
					dist[to] = dist[v] + cost;
					par_v[to] = v;
					par_e[to] = e_id;

					if (!in_q[to])
					{
						q.push(to);
						in_q[to] = true;
					}
				}
			}
		}

		if (dist[t] == -INF)
			break;

		int push = INF;
		for (int i = t; i != s; i = par_v[i])
		{
			int e_id = par_e[i];
			int can = e_list[e_id].cap - e_list[e_id].flow;
			push = min(push, can);
		}

		ans_flow += push;

		for (int i = t; i != s; i = par_v[i])
		{
			int e_id = par_e[i];
			int cost = e_list[e_id].cost;
			ans_cost += push * cost;
			e_list[e_id].flow += push;
			e_list[e_id ^ 1].flow -= push;
		}
	}

	assert(ans_flow == p_cnt + s_cnt);

	vector<int> list1, list2;
	
	for (int e_id = 0; e_id < e_cnt; e_id++)
	{
		int v = e_list[e_id].v;
		int to = e_list[e_id].to;
		int f = e_list[e_id].flow;
		
		if (0 <= v && v < n && to == pv && f == 1)
			list1.push_back(v);

		if (0 <= v && v < n && to == sv && f == 1)
			list2.push_back(v);
	}

	sort(list1.begin(), list1.end());
	sort(list2.begin(), list2.end());

	printf("%d\n", ans_cost);
	for (int x : list1)
		printf("%d ", x + 1);
	printf("\n");
	for (int x : list2)
		printf("%d ", x + 1);
	printf("\n");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}