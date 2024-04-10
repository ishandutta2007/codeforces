#include <bits/stdc++.h>
using lint = long long int;
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


int main()
{
    string S;
    cin >> S;
    vector<lint> cnt1(26);
    vector<vector<lint>> cnt2(26, vector<lint>(26));

    for (auto c : S) {
        int i = c - 'a';
        REP(d, 26) cnt2[d][i] += cnt1[d];
        cnt1[i] += 1;
    }
    lint ret = *max_element(cnt1.begin(), cnt1.end());
    for (auto v : cnt2) ret = max(ret, *max_element(v.begin(), v.end()));
    cout << ret << endl;
}