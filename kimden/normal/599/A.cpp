#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(min(a + b + c, a + a + b + b), min(a + a + c + c, c + c + b + b)) << endl;
    return 0;
}