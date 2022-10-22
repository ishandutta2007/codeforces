#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define razmak(x) cout << x << " _ "
#define red(x) cout << x << endl
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    cout << 3*( n-3 ) + ( n-3 )*( n-4 ) + 1;
    return 0;
}