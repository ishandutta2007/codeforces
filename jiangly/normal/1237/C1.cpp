#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        auto &[x, y, z, j] = p[i];
        cin >> x >> y >> z;
        j = i + 1;
    }
    sort(p.begin(), p.end());
    int lst = -1;
    auto work = [&](int l, int r) {
        int lst = -1;
        for (int i = l; i < r; ) {
            int j = i;
            while (j < r && get<1>(p[j]) == get<1>(p[i])) ++j;
            for (int k = i; k + 1 < j; k += 2) cout << get<3>(p[k]) << " " << get<3>(p[k + 1]) << "\n";
            int x = -1;
            if ((j - i) % 2 == 1)
                x = j - 1;
            if (x != -1) {
                if (lst == -1)
                    lst = x;
                else {
                    cout << get<3>(p[lst]) << " " << get<3>(p[x]) << "\n";
                    lst = -1;
                }
            }
            i = j;
        }
        return lst;
    };
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && get<0>(p[j]) == get<0>(p[i])) ++j;
        int x = work(i, j);
        if (x != -1) {
            if (lst == -1)
                lst = x;
            else {
                cout << get<3>(p[lst]) << " " << get<3>(p[x]) << "\n";
                lst = -1;
            }
        }
        i = j;
    }
    return 0;
}