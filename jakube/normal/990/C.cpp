#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<int, int> starting, ending;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int x = 0;
        bool good = true;
        for (char c : s) {
            if (c == '(')
                x++;
            else
                x--;
            if (x < 0)
                good = false;
        }
        if (good) {
            starting[x]++;
        }

        x = 0;
        good = true;
        reverse(s.begin(), s.end());
        for (char c : s) {
            if (c == ')')
                x++;
            else
                x--;
            if (x < 0)
                good = false;
        }

        if (good) {
            ending[x]++;
        }
    }

    long long total = 0;
    for (auto [x, cnt] : starting) {
        total += cnt * (long long)ending[x];
    }
    cout << total << '\n';
}