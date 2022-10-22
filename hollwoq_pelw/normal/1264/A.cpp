#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        
        int cnt = n / 2;
        while (cnt > 0 && p[cnt - 1] == p[cnt]) --cnt;
        
        if (cnt == 0) {
            cout << "0 0 0\n";
            continue;
        }
        int g = 1;
        while (g < cnt && p[g - 1] == p[g]) {
            ++g;
        }
        int s = g + 1;
        while (g + s < cnt && p[g + s - 1] == p[g + s]) {
            ++s;
        }
        int b = cnt - g - s;
        if (b > g) {
            cout << g << " " << s << " " << b << '\n';
        }else {
            cout << "0 0 0\n";
        }
    }
    return 0;
}