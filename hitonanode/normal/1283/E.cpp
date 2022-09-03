#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N;
    cin >> N;
    vector<int> X(N);
    cin >> X;
    sort(X.begin(), X.end());
    int ret_lo = 0, ret_hi = 0;
    int l_lo = -2, l_hi = -2;
    for (auto x : X) {
        if (x - 1 > l_lo) {
            ret_lo++;
            l_lo = x + 1;
        }
        if (x + 1 > l_hi) {
            ret_hi++;
            l_hi = max(l_hi + 1, x - 1);
        }
    }
    cout << ret_lo << " " << ret_hi << endl;
}