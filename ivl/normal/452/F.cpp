#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define pb push_back

using namespace std;

const int MOD = 1000000007;

class mint{
public:
    int x;
    mint(ll y = 0){y %= MOD; if (y < 0) y += MOD; x = y;}
};
mint operator+(mint a, mint b){a.x += b.x; if (a.x >= MOD) a.x -= MOD; return a;}
mint operator-(mint a, mint b){a.x -= b.x; if (a.x < 0) a.x += MOD; return a;}
mint operator*(mint a, mint b){return mint((ll)a.x * b.x);}
void operator+=(mint &a, mint b){a = a + b;}
void operator-=(mint &a, mint b){a = a - b;}
void operator*=(mint &a, mint b){a = a * b;}
bool operator==(mint a, mint b){return a.x == b.x;}
mint operator^(mint a, int x){
    mint r = 1;
    while (x){
        if (x & 1) r *= a;
        a *= a;
        x >>= 1;
    } return r;
}

mint P = 101;
mint Pow[1000005];
mint Pow2[1000005];

const int offset = (1 << 20);
class Turnament{
public:
    mint V[offset * 2];
    Turnament(){for (auto &x : V) x = 0;}
    void add(int id, int lo, int hi, int pos, mint val){
        if (lo > pos || hi < pos) return;
        V[id] += val;
        if (lo == hi) return;
        int mid = (lo + hi) / 2;
        add(id * 2, lo, mid, pos, val);
        add(id * 2 + 1, mid + 1, hi, pos, val);
    }
    void add(int pos, mint val){add(1, 0, offset - 1, pos, val);}
    mint sum(int id, int lo, int hi, int slo, int shi){
        if (lo > shi || hi < slo) return 0;
        if (lo >= slo && hi <= shi) return V[id];
        int mid = (lo + hi) / 2;
        return sum(id * 2, lo, mid, slo, shi) + sum(id * 2 + 1, mid + 1, hi, slo, shi);
    }
    mint sum(int lo, int hi){return sum(1, 0, offset - 1, lo, hi);}
};

class MyString{
public:
    vector < mint > S;
    Turnament H1, H2;
    MyString(int Size = offset){
        REP(Size) S.pb(0);
    }
    void change(int pos, mint val){
        H1.add(pos, (val - S[pos]) * Pow[pos]);
        H2.add(pos, (val - S[pos]) * Pow[S.size() - 1 - pos]);
    }
    bool query(int lo, int hi){return H1.sum(lo, hi) * Pow2[lo] == H2.sum(lo, hi) * Pow2[S.size() - 1 - hi];}
} S(400000);

int n;
int per[300005];

void NO(){printf("NO\n"); exit(0);}
void YES(){printf("YES\n"); exit(0);}

int main(){

    Pow[0] = Pow2[0] = 1;
    Pow[1] = P;
    Pow2[1] = P ^ (MOD - 2);
    FOR(2, 1000005, i) Pow[i] = Pow[i - 1] * Pow[1], Pow2[i] = Pow2[i - 1] * Pow2[1];

    scanf("%d", &n);
    FOR(0, n, i) scanf("%d", per + i);

    FOR(0, n, i){
        int x = per[i] - 1;
        S.change(x, 1);
        int D = min(x, n - 1 - x);
        if (!S.query(x - D, x + D)) YES();
    } NO();

    return 0;
}