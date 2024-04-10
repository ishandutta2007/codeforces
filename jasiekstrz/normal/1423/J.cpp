#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t q;
    cin >> q;

    while(q --> 0) {
        int64_t nn;
        cin >> nn;

        __extension__ __int128 n = nn;
        cout << int64_t((((n+1) * (n + (n%2 ? -1 : 1) + 6) + 9) / 16) % int64_t(1e9+7)) << '\n';
    }
}