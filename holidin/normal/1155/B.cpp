#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

int main() {
    string s;
    int i, j, k, n, cnt = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (i = 0; i < n - 10; ++i)
    if (s[i] == '8')
        ++cnt;
    if (cnt <= (n - 11) / 2)
        cout << "NO";
    else
        cout << "YES";
}