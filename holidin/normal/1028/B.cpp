#include <bits/stdc++.h>
using namespace std;

int i, j, n, m;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (i = 0; i < 2000; ++i)
    if (i % 2 == 1)
        cout << 0;
    else
        cout << 9;
    cout << 9 << endl;
    for (i = 1; i < 2000; ++i)
    if (i % 2 == 0)
        cout << 0;
    else
        cout << 9;
    cout << 1;
}