#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fi first
#define se second
using namespace std;
const int N = 4e5 + 1;
int sumclose[N];

void solve() {
    int i, j, n;
    string s;
    vector <int> vopen, vclose;
    cin >> s;
    sumclose[s.size()] = 0;
    for (i = s.size() - 1; i >= 0; --i)
        sumclose[i] = sumclose[i + 1] + (s[i] == ')');
    for (i = 0; i < s.size(); ++i)
    if (s[i] == '(' && sumclose[i + 1] >= vopen.size() + 1)
        vopen.push_back(i + 1);
    for (i = s.size() - 1; i >= 0; --i)
    if (s[i] == ')' && vclose.size() < vopen.size())
        vclose.push_back(i + 1);
    if (vopen.size() == 0)
        cout << 0 << "\n";
    else {
        cout << 1 << "\n";
        cout << 2 * vopen.size() << "\n";
        for (i = 0; i < vopen.size(); ++i)
            cout << vopen[i] << ' ';
        for (i = (int)vclose.size() - 1; i >= 0; --i)
            cout << vclose[i] << ' ';
        cout << "\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    solve();
}