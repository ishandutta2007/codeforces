#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    sort(A.begin(), A.end());
    REP(i, N) {
        if (i == 0) {
            if (A[i] > 1) A[i]--;
        }
        else
        {
            if (A[i] > A[i - 1] + 1) A[i]--;
            else if (A[i] <= A[i - 1]) A[i]++;
        }
    }
    set<int> cand;
    for (auto v : A) cand.insert(v);
    cout << cand.size() << endl;
}