#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> pos(n);
    int po = 0;
    for (auto& x : a) {
        cin >> x;
        x--;
        pos[x] = po++;
    }
    vector<int> group(n, 0);
    vector<int> next_left(n), next_right(n);
    iota(next_left.begin(), next_left.end(), -1);
    iota(next_right.begin(), next_right.end(), 1);
    
    int turn = 1;
    for (int x = n-1; x >= 0; x--) {
        int po = pos[x];
        if (group[po])
            continue;

        group[po] = turn;

        int cur = next_left[po];
        for (int i = 0; i < k && cur > -1; i++) {
            group[cur] = turn;
            cur=next_left[cur];
        }
        int nl = cur;

        cur = next_right[po];
        for (int i = 0; i < k && cur < n; i++) {
            group[cur] = turn;
            cur=next_right[cur];
        }
        int nr = cur;

        if (nr < n)
            next_left[nr] = nl;
        if (nl >= 0)
            next_right[nl] = nr;

        turn ^= 3;
    }

    for (auto x : group) {
        cout << x;
    }
    cout << '\n';
}