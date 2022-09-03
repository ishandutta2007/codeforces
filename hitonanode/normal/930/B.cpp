#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


int main()
{
    string S;
    cin >> S;
    string T = S + S;
    vector<vector<string>> vs(26);
    int N = S.length();
    REP(i, N)
    {
        string U = T.substr(i, N);
        vs[U[0] - 'a'].push_back(U);
    }
    int ok = 0;
    for (auto v : vs) if (v.size()) {
        int K = v.size();
        vector<int> cnt(26);
        int add = 0;
        REP(i, N)
        {
            int tmp = 0;
            fill(cnt.begin(), cnt.end(), 0);
            REP(j, K) cnt[v[j][i] - 'a']++;
            for (auto x : cnt) tmp += (x == 1);
            chmax(add, tmp);
        }
        ok += add;
    }
    cout << ok * 1.0 / S.length() << "\n";
}