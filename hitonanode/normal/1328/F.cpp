#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

lint sol2(vector<lint> A, lint K, lint t) {
    for (auto x : A) if (x == t) K--;
    if (K <= 0) return 0;

    int nb = 0;
    lint cost = 0;
    for (auto x : A) if (x < t) cost += t - x, nb++;
    if (nb < K) return 1e18;
    else return cost - (nb - K);
}

lint solve(vector<lint> A, lint K) {
    map<lint, int> cnt;
    for (auto x : A) cnt[x]++;
    for (auto p : cnt) if (p.second >= K) return 0;

    lint tmp = sol2(A, K, A[K - 1]);
    if (K < A.size()) chmin(tmp, sol2(A, K, A[K]));

    lint med = A[A.size() / 2];
    int notsame = 0;
    lint c2 = 0;
    for (auto x : A) {
        c2 += abs(med - x);
        if (x != med) notsame++;
    }
    c2 -= min<int>(notsame, A.size() - K);
    chmin(tmp, c2);
    return tmp;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<lint> A(N);
    cin >> A;
    sort(A.begin(), A.end());

    lint ret1 = solve(A, K);
    for (auto &a : A) a = 1010101010 - a;
    sort(A.begin(), A.end());
    lint ret2 = solve(A, K);
    cout << min(ret1, ret2) << endl;
}