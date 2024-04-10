#include <iostream>
using namespace std;
using lint = long long;

lint solve()
{
    lint N, K;
    cin >> N >> K;
    return (K - 1) / (N - 1) * N + (K - 1) % (N - 1) + 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}