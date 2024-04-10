#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        cin >> A;
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        if (A.size() > K)
        {
            cout << -1 << '\n';
            continue;
        }
        while (A.size() < K) A.push_back(1);
        cout << N * A.size() << '\n';
        for (int t = 0; t < N; t++)
        {
            for (auto a : A) cout << a << ' ';
        }
        cout << '\n';
    }
}