#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;

ostream &operator<<(ostream &out, string str)
{
    for (char c : str)
        out << c;
    return out;
}
template <class L, class R>
ostream &operator<<(ostream &out, pair<L, R> p)
{
    return out << "(" << p.st << ", " << p.nd << ")";
}
template <class T>
auto operator<<(ostream &out, T a) -> decltype(a.begin(), out)
{
    out << '{';
    for (auto it = a.begin(); it != a.end(); it = next(it))
        out << (it != a.begin() ? ", " : "") << *it;
    return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts>
void dump(T a, Ts... x)
{
    cerr << a << ", ";
    dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

#define int long long
//#define __int128_t long long

const int MAX = (int)2e18;
vector<string> trzy = {"3 + 3", "3 ^ 6", " 3 + 5 ", "3 + 6", "8 ^ 9"};

vector<string> operacje;

string pluss(int x, int y)
{
    return to_string(x) + " + " + to_string(y);
}
string xorr(int x, int y)
{
    return to_string(x) + " ^ " + to_string(y);
}

void generate_pow(int x)
{
    while (x < MAX)
    {
        operacje.push_back(pluss(x, x));
        x *= 2;
    }
}

int mult(int x, int y, int MOD)
{
    __int128_t X = x;
    __int128_t Y = y;
    __int128_t M = MOD;
    __int128_t res = (X * Y) % M;

    return res;
}

int fas_pow(int x, int pot, int MOD)
{
    // debug(x, pot, MOD);
    if (pot == 0)
        return 1;
    if (pot % 2 == 1)
        return mult(fas_pow(x, pot - 1, MOD), x, MOD);
    else
    {
        int A = fas_pow(x, pot / 2, MOD);
        return mult(A, A, MOD);
    }
}

void mult(int x, int S)
{
    int cur = 0;
    for (int i = 0; i < 61; i++)
        if (S & (1ll << i))
        {
            if (cur != 0)
                operacje.push_back(pluss(cur, (1ll << i) * x));
            cur += (1ll << i) * x;
        }
    return;
}

void solve(int x)
{
    // debug(x);
    if (x == 1)
        return;

    generate_pow(x);

    int MOD1 = 1ll << 21;
    int MOD2 = 1ll << 41;

    int A = fas_pow(x, MOD1 / 2 - 1, MOD1);
    int B = fas_pow(x, MOD2 / 2 - 1, MOD2);

    operacje.push_back(pluss(x, x));
    mult(x, A);
    operacje.push_back(pluss(x, x));
    mult(x, B);

    A *= x;
    B *= x;

    //  debug(A, B);
    operacje.push_back(pluss(B, A));
    int C = B + A;

    operacje.push_back(xorr(B, A));
    int D = B ^ A;

    // debug(C, D, C ^ D);

    operacje.push_back(xorr(C, D));

    generate_pow(2);
    for (int i = 1; i < 61; i++)
        if (x & (1ll << i))
        {
            operacje.push_back(xorr(x, (1ll << i)));
            x ^= (1ll << i);
        }
    //  solve(x);
    return;
}

void app(set<int> &Q, string s)
{
    stringstream st(s);
    int a, b;
    char c;
    st >> a >> c >> b;
    // debug(a, b, c);
    assert(Q.find(a) != Q.end() && Q.find(b) != Q.end());
    if (c == '^')
        Q.insert(a ^ b);
    else
        Q.insert(a + b);
}

int32_t main()
{

    int q;
    cin >> q;
    solve(q);
    cout << operacje.size() << endl;

    set<int> S = {q};

    for (auto s : operacje)
    {
        cout << s << endl;
        app(S, s);
    }
    assert(S.count(1) > 0);
}