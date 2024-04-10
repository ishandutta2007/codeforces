#include <bits/stdc++.h>
using namespace std;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


bool solve()
{
    vector<int> v(3);
    cin >> v;
    sort(v.begin(), v.end());
    int N;
    cin >> N;
    int d = N - v[2] * 2 + v[1] + v[0];
    return d >= 0 and d % 3 == 0;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << endl;
}