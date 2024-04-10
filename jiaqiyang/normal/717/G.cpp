/* Copyright 2016 AcrossTheSky */
#include <iostream>
#include <cstdio>
#include <utility>
#include <cassert>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define RVC(i, c) fot (int i = 0; i < (c).size(); ++i)
#define RED(k, u) for (int k = head[(u)]; k; k = edge[k].next)
#define lowbit(x) ((x) & (-(x)))
#define CL(x, v) memset(x, v, sizeof x)
#define MP std::make_pair
#define PB push_back
#define FR first
#define SC second
#define rank rankk
#define next nextt
#define link linkk
#define index indexx
#define abs(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

template<class T> inline
bool getmin(T *a, const T &b) {
    if (b < *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
bool getmax(T *a, const T &b) {
    if (b > *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
void read(T *a) {
    char c;
    while (isspace(c = getchar())) {}
    bool flag = 0;
    if (c == '-') flag = 1, *a = 0;
    else
        *a = c - 48;
    while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
    if (flag) *a = -*a;
}
const int mo = 1000000007;
template<class T>
T pow(T a, T b, int c = mo) {
    T res = 1;
    for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c) if (b & i) res = 1LL * res * a % c;
    return res;
}
/*======================= TEMPLATE =======================*/
const int INF = 0x3f3f3f3f;  
const int maxn = 600;  
struct Edge {  
  int from, to, cap, flow, cost;  
};  
  
struct MCMF {  
  int n, m, s, t;  
  vector<Edge> edges;  
  vector<int> G[maxn];  
  int inq[maxn];       
  int d[maxn];        
  int p[maxn];       
  int a[maxn];       
  
  void init(int n) {  
    this->n = n;  
    for(int i = 0; i < n; i++) G[i].clear();  
    edges.clear();  
  }  
  
  void AddEdge(int from, int to, int cap, int cost) {  
    edges.push_back((Edge){from, to, cap, 0, cost});  
    edges.push_back((Edge){to, from, 0, 0, -cost});  
    m = edges.size();  
    G[from].push_back(m-2);  
    G[to].push_back(m-1);  
  }  
  
  bool BellmanFord(int s, int t, int& flow, int& cost) {  
    for(int i = 0; i < n; i++) d[i] = INF;  
    memset(inq, 0, sizeof(inq));  
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;  
  
    queue<int> Q;  
    Q.push(s);  
    while(!Q.empty()) {  
      int u = Q.front(); Q.pop();  
      inq[u] = 0;  
      for(int i = 0; i < G[u].size(); i++) {  
        Edge& e = edges[G[u][i]];  
        if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {  
          d[e.to] = d[u] + e.cost;  
          p[e.to] = G[u][i];  
          a[e.to] = min(a[u], e.cap - e.flow);  
          if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }  
        }  
      }  
    }  
    if(d[t] == INF) return false;  
    flow += a[t];  
    cost += d[t] * a[t];  
    int u = t;  
    while(u != s) {  
      edges[p[u]].flow += a[t];  
      edges[p[u]^1].flow -= a[t];  
      u = edges[p[u]].from;  
    }  
    return true;  
  }  
  
  int Mincost(int s, int t) {  
    int cost = 0, flow = 0;  
    while(BellmanFord(s, t, flow, cost));  
    return cost;  
  }  
}G;

int n, m, x;
map<string, int> S;
string T, P;
char c[maxn];

int main() {
	cin >> n;
	scanf("%s", c);
	T.assign(c);
	G.init(n + 3);
	int s = n + 1, t = n;
	cin >> m;
	REP(i, 1, m) {
		int x;
		scanf("%s%d", c, &x);
		P.assign(c);
		S[P] = x;
	}
	REP(i, 0, n - 1) 
		REP(j, 1, n - i) if (S.find(T.substr(i, j)) != S.end())  
		G.AddEdge(i, i + j, 1, -S[T.substr(i, j)]);
	REP(i, 0, n - 2) G.AddEdge(i, i + 1, INF, 0);
	cin >> x;
	G.AddEdge(s, 0, x, 0);
	G.AddEdge(n - 1, t, x, 0);
	cout << -G.Mincost(s, t) << endl;
	return 0;
}