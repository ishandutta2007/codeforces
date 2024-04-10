#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N;
    cin >> N;
    vector<lint> nl(4e5), nr(4e5);
    lint nz = 0;
    while (N--)
    {
        string s;
        cin >> s;
        int dl = 0, dnow = 0;
        for (auto c : s) {
            if (c == '(') dnow++;
            else dnow--;
            chmin(dl, dnow);
        }
        if (dl == 0 and dnow == 0) nz++;
        else if (dl == 0 and dnow > 0) nl[dnow]++;
        else if (dnow < 0 and dl == dnow) nr[abs(dnow)]++;
    }
    lint ret = nz * nz;
    REP(i, nl.size()) ret += nl[i] * nr[i];
    cout << ret << "\n";
}