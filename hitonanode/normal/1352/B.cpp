#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> ret(K, 1);
    if ((N - K) % 2) ret.assign(K, 2);
    int rem = N - ret[0] * K;
    if (rem < 0 or rem % 2)
    {
        cout << "NO\n";
        return;
    }
    ret[0] += rem;
    cout << "YES\n";
    for (auto x : ret) cout << x << ' ';
    cout << '\n';
}
int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}