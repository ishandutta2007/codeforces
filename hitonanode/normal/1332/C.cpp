#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int solve()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int ret = 0;
    REP(k, K) {
        int i = k;
        int j = K - 1 - k;
        if (i > j) continue;
        array<int, 26> arr;
        REP(d, 26) arr[d] = 0;
        while (i < N) {
            arr[S[i] - 'a']++;
            if (j != i) arr[S[j] - 'a']++;
            i += K;
            j += K;
        }
        int hi = *max_element(arr.begin(), arr.end());
        ret += accumulate(arr.begin(), arr.end(), 0) - hi;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << "\n";
}