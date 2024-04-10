#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int N;
    cin >> N;
    int ne = 0, no = 0;
    while (N--) {
        int a;
        cin >> a;
        if (a % 2) no++;
        else ne++;
    }
    return (no % 2 or (no and ne));
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << endl;
}