#include<bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int n, m, a;
    cin >> n >> m >> a;
    cout << ((n + a - 1) / a) * ((m + a - 1) / a);
}