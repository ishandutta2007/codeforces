#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

string solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    int XOR = 0;
    for (auto x : A) XOR ^= x;
    if (!XOR) return "DRAW";
    int d = 32 - __builtin_clz(XOR) - 1;
    int cnt = 0;
    for (auto a : A) if ((a >> d) & 1) cnt++;
    if (cnt % 4 == 1 or N % 2 == 0) return "WIN";
    if (cnt % 4 == 3) return "LOSE";
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}