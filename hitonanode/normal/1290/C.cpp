#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

constexpr int FREE = 1;
constexpr int USE = 2;
constexpr int NOT_USE = 3;
constexpr int COMPETING = 4;

vector<int> STATE;
vector<int> comp;
int ret;

struct SizeAwareUnionFind
{
    vector<int> par, cou;
    SizeAwareUnionFind(int N) : par(N), cou(N) { REP(i, N) par[i] = i, cou[i] = 1; }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    void unite(int x, int y) {
        x = find(x), y = find(y); if (x == y) return;
        if (cou[x] < cou[y]) swap(x, y); 
        par[y] = x, cou[x] += cou[y];
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};
SizeAwareUnionFind uf(0);

void use(int i)
{
    i = uf.find(i);
    if (STATE[i] == FREE) {
        STATE[i] = USE;
        ret += uf.count(i);
    }
    else if (STATE[i] == COMPETING) {
        int n = uf.count(i);
        int m = uf.count(comp[i]);
        ret = ret - min(n, m) + n;
        STATE[i] = USE;
        STATE[uf.find(comp[i])] = NOT_USE;
    }
}

void not_use(int i)
{
    i = uf.find(i);
    if (STATE[i] == FREE) {
        STATE[i] = NOT_USE;
    }
    else if (STATE[i] == COMPETING) {
        int n = uf.count(i);
        int m = uf.count(comp[i]);
        ret = ret - min(n, m) + m;
        STATE[i] = NOT_USE;
        STATE[uf.find(comp[i])] = USE;
    }
}

void xor_use(int i, int j) {
    i = uf.find(i), j = uf.find(j);
    if (STATE[i] == COMPETING and STATE[j] == COMPETING) {
        int k = uf.find(comp[i]), l = uf.find(comp[j]);
        if (k == j or i == l) return;
        ret -= min(uf.count(i), uf.count(k)) + min(uf.count(j), uf.count(l));
        uf.unite(j, k), uf.unite(i, l);
        i = uf.find(i), j = uf.find(j);
        ret += min(uf.count(i), uf.count(j));
        comp[i] = j;
        comp[j] = i;
        STATE[i] = STATE[j] = COMPETING;
        return;
    }
    REP(_, 2) {
        if (STATE[i] == COMPETING) {
            assert(STATE[j] == FREE);
            int k = uf.find(comp[i]);
            ret -= min(uf.count(i), uf.count(k));
            uf.unite(j, k);
            j = uf.find(j);
            ret += min(uf.count(i), uf.count(j));
            comp[i] = j;
            comp[j] = i;
            STATE[i] = STATE[j] = COMPETING;
            return;
        }
        swap(i, j);
    }
    assert(STATE[i] == FREE and STATE[j] == FREE);
    comp[i] = j, comp[j] = i;
    STATE[i] = STATE[j] = COMPETING;
    ret += min(uf.count(i), uf.count(j));
}

void xor_notuse(int i, int j) {
    i = uf.find(i), j = uf.find(j);
    if (i == j) return;
    if (STATE[i] == COMPETING and STATE[j] == COMPETING) {
        int k = uf.find(comp[i]), l = uf.find(comp[j]);
        ret -= min(uf.count(i), uf.count(k)) + min(uf.count(j), uf.count(l));
        uf.unite(i, j), uf.unite(k, l);
        i = uf.find(i);
        k = uf.find(k);
        ret += min(uf.count(i), uf.count(k));
        comp[i] = k;
        comp[k] = i;
        STATE[i] = STATE[k] = COMPETING;
        return;
    }
    REP(_, 2) {
        if (STATE[i] == COMPETING) {
            assert(STATE[j] == FREE);
            int k = uf.find(comp[i]);
            ret -= min(uf.count(i), uf.count(k));
            uf.unite(i, j);
            i = uf.find(i);
            ret += min(uf.count(i), uf.count(k));
            comp[i] = k;
            comp[k] = i;
            STATE[i] = STATE[k] = COMPETING;
            return;
        }
        swap(i, j);
    }
    assert(STATE[i] == FREE and STATE[j] == FREE);
    uf.unite(i, j);
}

int main()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    STATE.resize(K, FREE);
    comp.resize(K, -1);
    uf = SizeAwareUnionFind(K);

    vector<vector<int>> X(K);
    vector<vector<int>> pos2k(N);
    REP(k, K) {
        int c;
        cin >> c;
        X[k].resize(c);
        cin >> X[k];
        for (auto &x : X[k]) {
            x--;
            pos2k[x].push_back(k);
        }
    }

    REP(i, N) {
        if (S[i] == '0') {
            if (pos2k[i].size() == 1) {
                use(pos2k[i][0]);
            }
            else if (pos2k[i].size() == 2)
            {
                int a = uf.find(pos2k[i][0]), b = uf.find(pos2k[i][1]);
                if (STATE[a] == USE) not_use(b);
                else if (STATE[b] == USE) not_use(a);
                else if (STATE[a] == NOT_USE) use(b);
                else if (STATE[b] == NOT_USE) use(a);
                else xor_use(a, b);
            }
            else exit(8);
        }
        if (S[i] == '1') {
            if (pos2k[i].size() == 1) not_use(pos2k[i][0]);
            else if (pos2k[i].size() == 2) {
                int a = uf.find(pos2k[i][0]), b = uf.find(pos2k[i][1]);
                if (a == b) {}
                else if (STATE[a] == USE) use(b);
                else if (STATE[b] == USE) use(a);
                else if (STATE[a] == NOT_USE) not_use(b);
                else if (STATE[b] == NOT_USE) not_use(a);
                else xor_notuse(a, b);
            }
        }
        printf("%d\n", ret);
    }
}