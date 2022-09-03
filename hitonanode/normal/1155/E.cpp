#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream& operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream& operator<<(ostream &os, set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream& operator<<(ostream &os, multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream& operator<<(ostream &os, map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
// #define dbg(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
lint mod_inverse(lint a, lint m)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

vector<vector<lint>> gauss_jordan(vector<vector<lint>> mtr, lint mod)
{
    // Gauss-Jordan elimination 
    int H = mtr.size(), W = mtr[0].size(), c = 0;
    REP(h, H)
    {
        if (c == W) break;
        int piv = -1;
        FOR(j, h, H) if (mtr[j][c])
        {
            if (piv == -1 or abs(mtr[j][c]) > abs(mtr[piv][c])) piv = j;
        }
        if (piv == -1) { c++; h--; continue; }
        swap(mtr[piv], mtr[h]);
        if (h != piv) REP(w, W) mtr[piv][w] = mtr[piv][w] ? mod - mtr[piv][w] : 0; // 
        lint pivinv = mod_inverse(mtr[h][c], mod);
        FOR(hh, h + 1, H) IFOR(w, c, W) mtr[hh][w] = (mtr[hh][w] - mtr[h][w] * mtr[hh][c] % mod * pivinv % mod + mod) % mod;
        c++;
    }
    return mtr;
}

constexpr lint MOD = 1000003;

int main()
{
    vector<vector<lint>> mat(11, vector<lint>(12));
    for (int i = 0; i < 11; i++)
    {
        cout << "? " << i << endl;
        cin >> mat[i].back();
        int po = 1;
        for (int j = 0; j < 11; j++)
        {
            mat[i][j] = po;
            po = po * i % MOD;
        }
    }
    
    mat = gauss_jordan(mat, MOD);
    
    vector<lint> a(11);
    for (int i = 10; i >= 0; i--)
    {
        lint acc = MOD - mat[i].back();
        for (int j = i + 1; j < 11; j++) acc += a[j] * mat[i][j];
        acc = (acc % MOD + MOD) % MOD;
        a[i] = (MOD - acc) % MOD * mod_inverse(mat[i][i], MOD) % MOD;
    }
    // dbg(a);
    
    int ret = -1;
    for (int i = 0; i < MOD; i++)
    {
        lint z = 0, t = 1;
        REP(j, 11)
        {
            z += t * a[j] % MOD;
            t = t * i % MOD;
        }
        if (z % MOD == 0) ret = i;
    }
    cout << "! " << ret << endl;
}