#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    lint a = 0, b = 0;
    for (auto x : A) {
        lint t = x / 2;
        a += t;
        b += x - t;
        swap(a, b);
    }
    cout << min(a, b) << endl;
    // int st = -1;
    // int bad = 0;
    // for (auto a : A)
    // {
    //     if (a % 2) {
    //         if (st < 0) st = 0;
    //         else {
    //             if (st == 1) {
    //                 bad++;
    //                 st = 0;
    //             }
    //             else
    //             {
    //                 st = -1;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         if (st >= 0) st = 1 - st;
    //     }
    // }
    // if (st >= 0) bad++;
    // cout << (accumulate(ALL(A), 0LL) - bad) / 2 << endl;
}