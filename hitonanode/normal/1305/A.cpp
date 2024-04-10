#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    cin >> A >> B;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (auto x : A) printf("%d ", x);
    puts("");
    for (auto x : B) printf("%d ", x);
    puts("");
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}