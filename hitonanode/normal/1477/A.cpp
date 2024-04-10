#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> X(N);
    for (auto &x : X) cin >> x;
    long long g = accumulate(X.begin(), X.end(), 0LL, [&](auto a, auto b) { return gcd(a, abs(b - X[0])); });
    long long diff = abs(K - X[0]);
    if (diff and (g == 0 or diff % g)) return false;
    return true;
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << '\n';
}