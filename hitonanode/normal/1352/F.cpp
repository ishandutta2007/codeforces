#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

string solve()
{
    int N0, N1, N2;
    cin >> N0 >> N1 >> N2;
    int N = N0 + N1 + N2 + 1;
    if (!N1 and !N2) return string(N, '0');
    if (!N1 and !N0) return string(N, '1');
    string ret(N, N2 ? '1' : '0');
    for (int i = 1; i < N; i++)
    {
        if (N2 and ret[i - 1] == '1') N2--, ret[i] = '1';
        else if (N0 and ret[i - 1] == '0') N0--, ret[i] = '0';
        else ret[i] = '1' ^ '0' ^ ret[i - 1], N1--;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}