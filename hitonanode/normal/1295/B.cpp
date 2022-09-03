#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

int solve()
{
    int N, X;
    cin >> N >> X;
    string S;
    cin >> S;
    vector<int> cou(N * 4 + 1);
    int B = N * 2;
    int ac = B;

    int hi = B, lo = B;
    for (auto c : S) {
        cou[ac]++;
        if (c == '0') ac++; else ac--;
        mmax(hi, ac);
        mmin(lo, ac);
    }

    if (ac == B) {
        if (hi >= B + X and lo <= B + X) return -1;
        else return 0;
    }

    lint ret = 0, diff = ac - B;
    if (diff > 0) {
        if (X > N * 2) X -= (X - N) / diff * diff;
        while (X >= -N * 2) ret += cou[B + X], X -= diff;
    }
    else {
        if (X < -N * 2) X += (abs(X) - N) / (-diff) * (-diff);
        while (X <= N * 2) ret += cou[B + X], X -= diff;
    }

    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}