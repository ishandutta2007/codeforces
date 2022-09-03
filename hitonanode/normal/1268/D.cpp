#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


template<int VMAX>
struct DirectedGraphSCC64 {
    int V;
    const vector<bitset<VMAX>> &e, &einv;
    vector<int> vs, cmp;
    bitset<VMAX> unvisited;
    int scc_num;

    void _dfs(int now) {
        unvisited.reset(now);
        while (true) {
            int nxt = (unvisited & e[now])._Find_first();
            if (nxt >= V) break;
            _dfs(nxt);
        }
        vs.push_back(now);
    }
    void _rdfs(int now, int k) {
        unvisited.reset(now);
        cmp[now] = k;
        while (true) {
            int nxt = (unvisited & einv[now])._Find_first();
            if (nxt >= V) break;
            _rdfs(nxt, k);
        }
    }

    DirectedGraphSCC64(const vector<bitset<VMAX>> &edge, const vector<bitset<VMAX>> &edge_inv)
     : V(edge.size()), e(edge), einv(edge_inv), vs(edge.size()), cmp(edge.size()), scc_num(0)
    {
        unvisited.set();
        for (int i = 0; i < V; i++) if (unvisited[i]) _dfs(i);
        unvisited.set();
        for (int i = (int)vs.size() - 1; i >= 0; i--) if (unvisited[vs[i]]) {
            _rdfs(vs[i], scc_num++);
        }
    }
};


int main()
{
    int N;
    cin >> N;
    vector<bitset<2000>> e(N), einv(N);
    REP(i, N) {
        string S;
        cin >> S;
        REP(j, N) if (S[j] == '1') {
            e[i][j] = einv[j][i] = 1;
        }
    }

    auto g = DirectedGraphSCC64<2000>(e, einv);

    int nscc = g.scc_num;
    if (nscc <= 1) {
        puts("0 1");
        return 0;
    }

    int ret = 0;
    REP(i, N)
    {
        REP(j, N) if (i != j) e[i][j].flip(), e[j][i].flip(), einv[i][j].flip(), einv[j][i].flip();
        ret += (DirectedGraphSCC64<2000>(e, einv).scc_num == 1);
        REP(j, N) if (i != j) e[i][j].flip(), e[j][i].flip(), einv[i][j].flip(), einv[j][i].flip();
    }
    if (ret) {
        cout << "1 " << ret << endl;
        return 0;
    }

    if (nscc == 2) {
        lint n0 = 0, n1 = 0;
        REP(i, N) (g.cmp[i] ? n1 : n0)++;
        if (N == 4 and n0 * n1 == 3) {
            puts("-1");
            return 0;
        }
        cout << "2 " << n0 * n1 * 2 % 998244353 << endl;
    }
}