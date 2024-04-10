#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[4];
    for (int i = 0; i < 4; ++i)
        cin >> a[i];
    int n = a[0] + a[1] + a[2] + a[3];
    for (int i = 0; i < 4; ++i) {
        vector<int> b(a, a + 4), ans{i};
        if (b[i] == 0)
            continue;
        --b[i];
        while (true) {
            int nxt = -1;
            if (b[ans.back() ^ 1] > 0)
                nxt = ans.back() ^ 1;
            else if (ans.back() == 1 || ans.back() == 2)
                nxt = ans.back() ^ 3;
            if (nxt == -1 || b[nxt] == 0)
                break;
            --b[nxt];
            ans.push_back(nxt);
        }
        if (ans.size() == n) {
            cout << "YES\n";
            for (int j : ans)
                cout << j << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}