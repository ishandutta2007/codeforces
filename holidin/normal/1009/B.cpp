#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;


int a[N], b[N];

int main() {
    int i, j, n, q, top, l, r, t, k;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    string s1, s2, s3;
    bool flag = false;
    for (i = 0; i < s.size(); ++i)
    if (s[i] == '1')
        s2 += '1';
    else {
        if (s[i] == '2')
            flag = true;
        if (!flag)
            s1 += s[i];
        else
            s3 += s[i];
    }
    cout << s1 + s2 + s3;
}