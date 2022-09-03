#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int N;
    cin >> N;
    vector<int> b(2);
    while (N--) {
        int a;
        cin >> a;
        b[a % 2]++;
    }
    return b[0] * b[1] == 0;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << "\n";
}