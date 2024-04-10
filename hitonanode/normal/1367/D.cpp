#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

string solve()
{
    string S;
    cin >> S;
    int N;
    cin >> N;
    vector<int> B(N);
    cin >> B;
    vector<int> cnt(26);
    for (auto c : S) cnt[c - 'a']++;

    vector<int> finished(N);
    vector<int> ret(N, -1);
    REP(t, 100)
    {
        queue<int> q;
        REP(i, N) if (!finished[i] and !B[i])
        {
            finished[i] = 1, q.emplace(i), ret[i] = t;
        }
        if (q.empty()) break;
        while (q.size())
        {
            int i = q.front();
            REP(j, N) B[j] -= abs(i - j);
            q.pop();
        }
    }
    string str(N, '_');
    char c = 'z';
    REP(j, *max_element(ret.begin(), ret.end()) + 1)
    {
        int nb_j = 0;
        for (auto x : ret) nb_j += (x == j);
        while (cnt[c - 'a'] < nb_j) c--;
        REP(i, N) if (ret[i] == j) str[i] = c;
        c--;
    }
    return str;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}