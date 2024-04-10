#include <bits/stdc++.h>
using namespace std;
const int N = 256;

int i, n, c[N];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (i = 0; i < n; ++i)
        ++c[s[i]];
    bool flag = n == 1;
    for (i = 'a'; i <= 'z'; ++i)
                flag |= c[i] > 1;
    if (flag)
        cout << "Yes";
    else
        cout << "No";
}