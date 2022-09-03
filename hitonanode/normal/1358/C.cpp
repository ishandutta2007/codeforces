#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        lint x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (x2 - x1) * (y2 - y1) + 1 << '\n';
    }
}