#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long mod = 1e9 + 9;
const int N = 3e5 + 1;


int main() {
    int i, j, k, n, l, a, b;
    string s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    int tk = 0;
    for (i = 0; i < s.size() - 1; ++i)
    if ((s[i + 1] == 'a') ^ tk) {
        tk = 1 - tk;
        cout << "1 ";
    } else
        cout << "0 ";
    cout << tk;
}