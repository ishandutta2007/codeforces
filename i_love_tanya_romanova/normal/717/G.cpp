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

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
    string name = it -> substr((*it)[0] == ' ', it -> length());
    if (isalpha(name[0]))
	    cerr << name  << " = " << a << " ";
	else
	    cerr << name << " ";
	_print(++it, args...);
}

typedef long long int int64;

struct Edge
{
	int v, to, flow, cap, cost;
	Edge() : v(), to(), flow(), cap(), cost() {}
	Edge(int _v, int _to, int _cap, int _cost) :
		v(_v), to(_to), flow(0), cap(_cap), cost(_cost) {}
};

const int V = 600;
const int E = (int)1e6;
const int M = 150;
const int INF = (int)1e9;

vector<int> g[V];
int e_cnt;
Edge e_list[E];

int s, t;

int n;
string str;
int m;
string pat[M];
int p[M];
int x;

bool in_q[V];
int dist[V];
int par_v[V];
int par_e[V];

void add_edge(int v, int to, int cap, int cost)
{
	dbg(v, to, cap, cost);

	e_list[e_cnt] = Edge(v, to, cap, cost);
	g[v].push_back(e_cnt);
	e_cnt++;

	e_list[e_cnt] = Edge(to, v, 0, -cost);
	g[to].push_back(e_cnt);
	e_cnt++;
}

string read_string()
{
	string ss;
	cin >> ss;
	return ss;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	str = read_string();
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		pat[i] = read_string();
		scanf("%d", &p[i]);
	}
	scanf("%d", &x);

	s = 0;
	t = n + 1;

	dbg(s, t);

	for (int i = 0; i <= n; i++)
		add_edge(i, i + 1, x, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str.substr(i, (int)pat[j].length()) != pat[j])
				continue;

			add_edge(i + 1, (i + 1) + (int)pat[j].length(), 1, p[j]);
		}
	}

	int ans = 0;

	queue<int> q;

	while (true)
	{
		fill(dist, dist + V, -INF);
		dist[s] = 0;
		q.push(s);
		in_q[s] = true;

		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			in_q[v] = false;

			for (int e_id : g[v])
			{
				int to = e_list[e_id].to;
				int can = e_list[e_id].cap - e_list[e_id].flow;
			
				if (can > 0 && dist[to] < dist[v] + e_list[e_id].cost)
				{
					dist[to] = dist[v] + e_list[e_id].cost;
					par_v[to] = v;
					par_e[to] = e_id;

					if (!in_q[to])
					{
						in_q[to] = true;
						q.push(to);
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
			push = min(push, e_list[e_id].cap - e_list[e_id].flow);
		}

		for (int i = t; i != s; i = par_v[i])
		{
			int e_id = par_e[i];
			ans += e_list[e_id].cost * push;
			e_list[e_id].flow += push;
			e_list[e_id ^ 1].flow -= push;
		}
	}

	printf("%d\n", ans);

	return 0;
}