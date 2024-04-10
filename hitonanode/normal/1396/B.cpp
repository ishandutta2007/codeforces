#include <bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

bool solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    sort(A.rbegin(), A.rend());
    int tot = accumulate(A.begin(), A.end(), 0);
    if (A[0] > tot - A[0]) return true;
    else return tot % 2;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "T": "HL") << '\n';
}