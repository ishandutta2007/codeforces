#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

bool solve()
{
    lint P, Q, B;
    cin >> P >> Q >> B;
    lint g = gcd(P, Q);
    P /= g, Q /= g;
    while (true)
    {
        B = gcd(Q, B);
        if (B == 1) break;
        Q /= B;
    }
    return Q == 1;
}

int main()
{
    int N;
    cin >> N;
    while (N--) cout << (solve() ? "Finite" : "Infinite") << '\n';
}