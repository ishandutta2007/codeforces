#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


lint solve()
{
    lint A, B, N;
    cin >> A >> B >> N;
    lint t = 0;
    while (true)
    {
        if (A < B) swap(A, B);
        if (A > N) return t;
        B += A;
        t++;
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