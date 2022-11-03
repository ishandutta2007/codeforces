#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    int n, m, a;
    cin >> n >> m >> a;
    cout << ((n + a - 1) / a) * ll((m + a - 1) / a) << endl;

}