#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int ask(vector<int> v)
{
    cout << "? " << v.size();
    for (auto x : v) cout << ' ' << x;
    cout << endl;
    cout.flush();
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

bool answer(vector<int> v)
{
    cout << "!";
    for (auto x : v) cout << ' ' << x;
    cout << endl;
    cout.flush();
    string ret;
    cin >> ret;
    if (ret == "Incorrect") exit(0);
    return true;
}

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> belong(N + 1, -1);
    REP(i, K)
    {
        int C;
        cin >> C;
        vector<int> S(C);
        cin >> S;
        for (auto x : S) belong[x] = i;
    }

    vector<int> q(N);
    REP(i, N) q[i] = i + 1;
    int maxi = ask(q);
    int lo = 1, hi = N + 1; // [lo, hi)
    while (hi - lo > 1)
    {
        int c = (lo + hi) / 2;
        vector<int> q;
        FOR(i, lo, c) q.emplace_back(i);
        int val = ask(q);
        if (maxi == val) hi = c;
        else lo = c;
    }
    vector<int> ans(K, maxi);
    if (belong[lo] != -1)
    {
        vector<int> q;
        FOR(i, 1, N + 1) if (belong[i] != belong[lo]) q.emplace_back(i);
        ans[belong[lo]] = ask(q);
    }
    answer(ans);
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}