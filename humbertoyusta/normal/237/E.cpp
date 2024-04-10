    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 3030;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Most used functions--------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
vector<ii> fact(int x){
    vector<ii> ret;
    for(int i=2; i*i<=x; i++){
        if( x % i == 0 ){
            int cnt_ = 0;
            while( x % i == 0 )
                x /= i, cnt_ ++;
            ret.pb({i,cnt_});
        }
    }
    if( x > 1 ){
        ret.pb({x,1});
    }
    return ret;
}
/// My Code -------------------------------------------------

/*
	Minimum Cost Flow (Tomizawa, Edmonds-Karp)
	Complexity: O(F m log n), where F is the amount of maximum flow
	Tested: Codeforces [http://codeforces.com/problemset/problem/717/G]
*/

template<typename flow_type, typename cost_type>
struct min_cost_max_flow
{
	struct edge
	{
		size_t src, dst, rev;
		flow_type flow, cap;
		cost_type cost;
	};

	int n;
	vector<vector<edge>> adj;

	min_cost_max_flow(int n) : n(n), adj(n), potential(n), dist(n), back(n) {}

	void add_edge(size_t src, size_t dst, flow_type cap, cost_type cost)
	{
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap, cost});
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, 0, -cost});
	}

	vector<cost_type> potential;

	inline cost_type rcost(const edge &e)
	{
		return e.cost + potential[e.src] - potential[e.dst];
	}

	void bellman_ford(int source)
	{
		for (int k = 0; k < n; ++k)
			for (int u = 0; u < n; ++u)
				for (edge &e : adj[u])
					if (e.cap > 0 && rcost(e) < 0)
						potential[e.dst] += rcost(e);
	}

	const cost_type oo = numeric_limits<cost_type>::max();

	vector<cost_type> dist;
	vector<edge*> back;

	cost_type dijkstra(int source, int sink)
	{
		fill(dist.begin(), dist.end(), oo);

		typedef pair<cost_type, int> node;
		priority_queue<node, vector<node>, greater<node>> pq;

		for (pq.push({dist[source] = 0, source}); !pq.empty();)
		{
			node p = pq.top(); pq.pop();

			if (dist[p.second] < p.first) continue;
			if (p.second == sink) break;

			for (edge &e : adj[p.second])
				if (e.flow < e.cap &&
					dist[e.dst] > dist[e.src] + rcost(e))
				{
					back[e.dst] = &e;
					pq.push({dist[e.dst] = dist[e.src] + rcost(e),
							 e.dst});
				}
		}

		return dist[sink];
	}

	pair<flow_type, cost_type> max_flow(int source, int sink)
	{
		flow_type flow = 0;
		cost_type cost = 0;

		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;

		potential.assign(n, 0);
		dist.assign(n, 0);
		back.assign(n, nullptr);

		bellman_ford(source); // remove negative costs

		while (dijkstra(source, sink) < oo)
		{
			for (int u = 0; u < n; ++u)
				if (dist[u] < dist[sink])
					potential[u] += dist[u] - dist[sink];

			flow_type f = numeric_limits<flow_type>::max();

			for (edge *e = back[sink]; e; e = back[e->src])
				f = min(f, e->cap - e->flow);
			for (edge *e = back[sink]; e; e = back[e->src])
				e->flow += f, adj[e->dst][e->rev].flow -= f;

			flow += f;
			cost += f * (potential[sink] - potential[source]);

		}
		return {flow, cost};
	}
};

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, m;
    string s;
    cin >> s;
    n = s.size();
    s = '&' + s;
    vector<int> cnt(26);

    min_cost_max_flow<int, int> graph = min_cost_max_flow<int, int>(maxn);

    for(int i=1; i<=n; i++){
        cnt[s[i]-'a'] ++;
    }
    for(int i=1; i<=26; i++){
        graph.add_edge(i,maxn-1,cnt[i-1],0);
    }
    cin >> m;

    int sum = 0;
    int curr = 26;
    for(int i=1; i<=m; i++){
        string t;
        cin >> t;
        int c;
        cin >> c;
        sum += c;
        curr++;
        fill(all(cnt),0);
        for(int j=0; j<t.size(); j++){
            cnt[t[j]-'a'] ++;
        }
        graph.add_edge(0,curr,c,0);
        graph.add_edge(curr,maxn-2,c,0);
        for(int j=1; j<=26; j++){
            graph.add_edge(curr,curr+j,cnt[j-1],i);
            for(int k=1; k<=26; k++){
                if( ( j - 1 ) == ( k - 1 ) ){
                    graph.add_edge(curr+j,k,cnt[j-1],0);
                }
            }
        }
        curr += 26;
    }
    if( sum - n < 0 ){
        cout << -1 << '\n';
        return 0;
    }
    graph.add_edge(maxn-2,maxn-1,sum-n,0);
    ii flow = graph.max_flow(0,maxn-1);db(flow.f)
    if( flow.f == sum ) cout << flow.s << '\n';
        else cout << -1 << '\n';

    return 0;
}