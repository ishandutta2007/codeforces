#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n, s, p;
    cin >> k >> n >> s >> p;
    
    long long x = (n + s - 1) / s * k;
    cout << (x + p - 1) / p  << '\n';
}