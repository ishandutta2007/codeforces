#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<string> transpose(vector<string> S)
{
    int H = S.size(), W = S[0].length();
    vector<string> ret(W, string(H, '0'));
    REP(i, H) REP(j, W) ret[j][i] = S[i][j];
    return ret;
}
bool checker(vector<string> S)
{
    bool blank1 = false, blank2 = false;
    int H = S.size(), W = S[0].length();
    REP(i, H)
    {
        bool tmp = true;
        for (auto c : S[i]) if (c == '#') tmp = false;
        blank1 |= tmp;
    }
    REP(j, W)
    {
        bool tmp = true;
        REP(i, H) if (S[i][j] == '#') tmp = false;
        blank2 |= tmp;
    }
    if (blank1 ^ blank2) return false;

    REP(_, 2)
    {
        int H = S.size(), W = S[0].length();
        REP(i, H)
        {
            int phase = 0;
            REP(j, W)
            {
                if (S[i][j] == '#')
                {
                    if (phase >= 2) return false;
                    if (phase == 0) phase = 1;
                }
                else
                {
                    if (phase == 1) phase = 2;
                }
            }
        }
        S = transpose(S);
    }
    return true;
}
void ng()
{
    puts("-1");
    exit(0);
}

struct GridUnionFind
{
    int H, W;
    std::vector<int> par, cou;
    using P = std::pair<int, int>;
    GridUnionFind(int H_, int W_) : H(H_), W(W_), par(H * W), cou(H * W, 1) { std::iota(par.begin(), par.end(), 0); }
    inline int id_(int h, int w) { return h * W + w; }
    inline bool coordinate_valid(int h, int w) { return h >= 0 and h < H and w >= 0 and w < W; }
    int _find(int x) { return (par[x] == x) ? x : (par[x] = _find(par[x])); }
    bool _unite(int x, int y) {
        x = _find(x), y = _find(y); if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int find(int h, int w) {
        assert(coordinate_valid(h, w));
        return _find(id_(h, w));
    }
    bool unite(int h, int w, int h2, int w2) {
        assert(coordinate_valid(h, w) and coordinate_valid(h2, w2));
        return _unite(id_(h, w), id_(h2, w2));
    }
    int count(int h, int w) { return cou[find(h, w)]; }
    bool same(int h, int w, int h2, int w2) { return find(h, w) == find(h2, w2); }

    int find(P p) { return find(p.first, p.second); }
    bool unite(P p, P p2) { return unite(p.first, p.second, p2.first, p2.second);  }
    int count(P p) { return count(p.first, p.second); }
    bool same(P p, P p2) { return same(p.first, p.second, p2.first, p2.second); }

    void merge_outer() {
        for (int h = 0; h < H - 1; h++) unite(h, 0, h + 1, 0), unite(h, W - 1, h + 1, W - 1);
        for (int w = 0; w < W - 1; w++) unite(0, w, 0, w + 1), unite(H - 1, w, H - 1, w + 1);
    }
    friend std::ostream &operator<<(std::ostream &os, GridUnionFind &g)
    {
        constexpr int WW = 3;
        os << "[(" << g.H << " * " << g.W << " grid)\n";
        for (int i = 0; i < g.H; i++) {
            for (int j = 0; j < g.W - 1; j++) {
                os << std::setw(WW) << g.find(i, j) << (g.same(i, j, i, j + 1) ? '-' : ' ');
            }
            os << std::setw(WW) << g.find(i, g.W - 1) << '\n';
            if (i < g.H - 1) {
                for (int j = 0; j < g.W; j++) os << std::setw(WW + 1) << (g.same(i, j, i + 1, j) ? "| " : "  ");
                os << "\n";
            }
        }
        os << "]\n";
        return os;
    }
};

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    cin >> S;
    int nb_b = 0;
    for (auto str : S) for (auto c : str) nb_b += (c == '#');
    if (!nb_b)
    {
        puts("0");
        return 0;
    }
    if (!checker(S)) ng();
    GridUnionFind uf(H, W);
    REP(i, H) REP(j, W - 1)
    {
        if (S[i][j] == '#' and S[i][j + 1] == '#') uf.unite(i, j, i, j + 1);
    }
    REP(i, H - 1) REP(j, W)
    {
        if (S[i][j] == '#' and S[i + 1][j] == '#') uf.unite(i, j, i + 1, j);
    }
    set<int> s;
    REP(i, H) REP(j, W) if (S[i][j] == '#') s.insert(uf.find(i, j));
    cout << s.size() << '\n';
}