#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

int solve()
{
    int N, X;
    cin >> N >> X;
    set<int> A;
    while (N--) {
        int a;
        cin >> a;
        A.insert(a);
    }
    if (A.count(X)) return 1;
    int M = *prev(A.end());
    int tmp = (X + M - 1) / M;
    return max(tmp, 2);
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}