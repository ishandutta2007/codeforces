#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

bool solve()
{
    lint A, B, N, S;
    cin >> A >> B >> N >> S;
    lint rem = S - N * min(S / N, A);
    return rem <= B;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << endl;
}