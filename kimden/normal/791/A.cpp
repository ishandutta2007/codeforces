#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int a, b;
    cin >> a >> b;
    int i = 0;
    for(; a <= b; ++i, a *= 3, b *= 2);
    cout << i << endl;
}