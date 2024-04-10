#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    cout << (k == 1 ? n : (1LL << (64 - __builtin_clzll(n))) - 1) << endl;
}