#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }



int main()
{
    int N;
    cin >> N;
    string s = to_string(N);
    int ret = 0;
    for (auto c : s) chmax<int>(ret, c - '0');
    vector<int> vec(ret);
    int p = 1;
    while (N)
    {
        REP(i, N % 10)
        {
            vec[i] += p;
        }
        p *= 10;
        N /= 10;
    }
    cout << ret << '\n';
    for (auto x : vec) cout << x << ' ';
    cout << '\n';
}