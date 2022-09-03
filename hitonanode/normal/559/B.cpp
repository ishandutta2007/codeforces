#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


string solve(string S) {
    const int N = S.length();
    int L = N;
    while (L % 2 == 0) L /= 2;
    while (L < N) {
        for (int i = 0; i < N; i += L * 2) {
            if (S.substr(i, L) > S.substr(i + L, L)) {
                REP(j, L) swap(S[i + j], S[i + j + L]);
            }
        }
        L *= 2;
    }
    return S;
}

int main()
{
    string A, B;
    cin >> A >> B;
    cout << (solve(A) == solve(B) ? "YES" : "NO") << '\n';
}