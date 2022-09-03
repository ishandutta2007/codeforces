#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    sort(A.rbegin(), A.rend());
    for (auto a : A) printf("%d ", a);
    puts("");
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}