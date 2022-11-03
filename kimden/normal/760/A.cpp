#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

//const ll mod = 1000000007;
//const ld eps = 1e-8;
//const int MAXN = 100002;


int main() {
    ios_base::sync_with_stdio(false);
    int m, d;
    cin >> m >> d;
    int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    d--;
    cout << ((a[m - 1] + d - 1) / 7 + 1) << endl;
    return 0;
}