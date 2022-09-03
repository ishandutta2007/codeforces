#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

bool solve()
{
    int N, K;
    cin >> N >> K;
    vector<lint> acc(100);
    while (N--) {
        lint a;
        cin >> a;
        int d = 0;
        while (a) {
            acc[d] += a % K;
            d++;
            a /= K;
        }
    }
    return *max_element(acc.begin(), acc.end()) <= 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << "\n";
}