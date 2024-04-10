#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    for (auto &a : A)
    {
        while (a % 2 == 0) a /= 2;
        while (a % 3 == 0) a /= 3;
    }
    sort(A.begin(), A.end());
    cout << (A[0] == A.back() ? "Yes" : "No") << '\n';
}