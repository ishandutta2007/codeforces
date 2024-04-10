#include <iostream>
#include <string>
using namespace std;

int solve() {
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    int tmin = 0;
    for (int i = 0; i < N - 1; i++) if (S[i] != S[i + 1]) tmin++;
    return max(((tmin + 1) / 2 + 1) * B, N * B) + N * A;
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}