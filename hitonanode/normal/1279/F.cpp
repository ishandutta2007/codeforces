#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////

struct DirectAcyclicGraph
{
    using Tedge = double;
    const Tedge InfE = 1e30;

    int V;
    std::vector<std::vector<std::pair<int, Tedge>>> to;
    DirectAcyclicGraph(int V = 0) : V(V), to(V) {}
    void add_edge(int s, int t, Tedge w) {
        assert(s < t);
        to[s].emplace_back(t, w);
    }

    // Calc the distance and No. of used edges between (s, x)
    std::pair<std::vector<Tedge>, std::vector<int>> shortest_path(int s, Tedge addcost = 0) {
        std::vector<Tedge> dist(V, InfE);
        dist[s] = 0;
        std::vector<int> cnte(V, 0);
        for (int i = s; i < V; i++) if (dist[i] < InfE) {
            for (auto &&p : to[i]) {
                Tedge dnew = dist[i] + p.second + addcost;
                if (dist[p.first] > dnew)
                {
                    dist[p.first] = dnew;
                    cnte[p.first] = cnte[i] + 1;
                }
            }
        }
        return std::make_pair(dist, cnte);
    }
};

int solve(vector<int> v, int K, int L)
{
    int N = v.size();
    if ((long long int)(K) * L >= N) return 0;
    DirectAcyclicGraph dag(N + 1);
    REP(i, N) dag.add_edge(i, i + 1, v[i]);
    REP(i, N - L + 1) dag.add_edge(i, i + L, 0);
    double lo = -N - 1, hi = 0.1;
    double dret;
    pair<vector<double>, vector<int>> q;
    REP(_, 50) {
        double c = (lo + hi) / 2;
        q = dag.shortest_path(0, c);
        double dv = q.first[N];
        int de = q.second[N];
        dret = dv - c * (N - (L - 1) * K);
        if (de > N - (L - 1) * K) lo = c;
        else if (de < N - (L - 1) * K) hi = c;
        else break;
    }
    return int(dret + 0.5);
}

int main()
{
    int N, K, L;
    cin >> N >> K >> L;
    string S;
    cin >> S;
    vector<int> v(N);
    REP(i, N) v[i] = (S[i] - 'A' >= 0 and S[i] - 'A' < 26);
    int ret = solve(v, K, L);
    REP(i, N) v[i] = (S[i] - 'a' >= 0 and S[i] - 'a' < 26);
    ret = min(ret, solve(v, K, L));
    if (L == 1) {
        int d = accumulate(v.begin(), v.end(), 0);
        int D = N - d;
        d -= K;
        D -= K;
        ret = max(0, min(d, D));
    }
    cout << ret << endl;
}