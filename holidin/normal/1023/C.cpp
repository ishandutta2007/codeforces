#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;

long long i, j, n, k, p = 0;
int a[N];
bool used[N];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int top = 0;
    cin >> s;
    for (i = 0; i < s.size(); ++i)
    if (s[i] == '(') {
        ++top;
        a[top] = i;
    } else {
        used[i] = true;
        used[a[top]] = true;
        --top;
        ++p;
        if (p == k / 2)
            break;
    }
    for (i = 0; i < n; ++i)
    if (used[i])
        cout << s[i];
}