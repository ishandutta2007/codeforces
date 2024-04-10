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
    int l = 0, lprv = 0, r = N - 1, rprv = 0;
    int cnt = 0, totl = 0, totr = 0;
    bool f = true;
    while (l <= r)
    {
        cnt++;
        if (f)
        {
            int tmp = 0;
            while (tmp <= rprv and l <= r) tmp += A[l++];
            totl += tmp;
            lprv = tmp;
            if (lprv <= rprv) break;
        }
        else
        {
            int tmp = 0;
            while (tmp <= lprv and l <= r) tmp += A[r--];
            totr += tmp;
            rprv = tmp;
            if (rprv <= lprv) break;
        }
        f ^= 1;
    }
    cout << cnt << ' ' << totl << ' ' << totr << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}