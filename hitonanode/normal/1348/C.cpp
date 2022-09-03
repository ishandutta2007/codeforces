#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

string solve()
{
    int N, K;
    string S;
    cin >> N >> K >> S;
    sort(S.begin(), S.end());
    string ret;

    ret += S[K - 1];
    if (S[0] < S[K - 1] or N == K)
    {
        return ret;
    }
    if (S[K] == S.back())
    {
        ret += string((N - K + K - 1) / K, S[K]);
        return ret;
    }
    else
    {
        ret += S.substr(K);
        return ret;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cout << solve() << '\n';
    }
}