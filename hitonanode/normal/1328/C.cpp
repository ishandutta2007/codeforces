#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


void solve()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    string T = S, U = S;
    int grater = 0;
    REP(i, N) {
        if (grater) {
            T[i] = '0', U[i] = S[i];
        }
        else {
            if (S[i] == '2') T[i] = U[i] = '1';
            else if (S[i] == '1') {
                grater = 1;
                T[i] = '1';
                U[i] = '0';
            }
            else {
                T[i] = U[i] = '0';
            }
        }
    }
    cout << T << "\n" << U << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}