#include <bits/stdc++.h>
using namespace std;

long long i, j, n, k;
string s, t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cout << max((long long)0, min((k - 1) / 2, n - k / 2)) << endl;
}