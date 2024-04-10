#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int N;
    cin >> N;
    map<int, int> mf, ml;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (!mf.count(a)) mf[a] = i;
        ml[a] = i;
    }
    for (auto p : mf) if (ml[p.first] > mf[p.first] + 1) return true;
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES\n" : "NO\n");
}