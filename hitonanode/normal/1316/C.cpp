#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> A(N), B(M);
    cin >> A >> B;
    int i = 0, j = 0;
    while (A[i] % P == 0) i++;
    while (B[j] % P == 0) j++;
    int n = i + j;
    cout << n << endl;
}