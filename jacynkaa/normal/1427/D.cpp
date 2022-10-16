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

int n;

vector<int> apply(vector<int> X, vector<int> moves)
{
    vector<int> res;
    for (int x : moves)
    {
        vector<int> Q(X.begin(), X.begin() + x);
        X.erase(X.begin(), X.begin() + x);
        res.insert(res.begin(), all(Q));
    }
    return res;
}
int get_idx(vector<int> X, int a)
{
    rep(i, sz(X)) if (X[i] == a) return i;
    return -1111;
}

vector<int> get_move(vector<int> X, int i)
{
    vector<int> move;
    rep(j, i)
        move.push_back(1);
    int A = get_idx(X, i + 1) - sz(move) + 1;
    move.push_back(A);
    int B = sz(X) - accumulate(all(move), 0);
    if (B)
        move.push_back(B);
    return move;
}

main()
{

    cin >> n;
    vector<int> X(n);
    rep(i, n) cin >> X[i];

    vector<vector<int>> M;
    rep(i, n)
    {
        vector<int> move;
        if (((n + i) % 2) == 0)
        {
            // debug("ST");
            move = get_move(X, i);
        }
        else
        {
            // debug("ND");
            auto tmp = X;
            reverse(all(tmp));
            move = get_move(tmp, i);
            reverse(all(move));
        }
        // debug(X, move);

        if (sz(move) > 1)
        {
            M.push_back(move);
            X = apply(X, move);
        }
    }
    debug(X);
    cout << M.size() << endl;
    for (auto m : M)
    {
        cout << sz(m) << " ";
        for (auto a : m)
            cout << a << " ";
        cout << endl;
    }
}