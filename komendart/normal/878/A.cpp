#include <bits/stdc++.h>

using namespace std;

const int bits = 10;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector< pair<string, int> > commands;
    for (int i = 0; i < n; ++i) {
        string tp; int x;
        cin >> tp >> x;
        commands.emplace_back(tp, x);
    }
    
    int ansxor = 0;
    int ansand = (1 << bits) - 1;
    int ansor = 0;
    for (int bit = 0; bit < bits; ++bit) {
        vector<int> f = {0, 1};
        for (int index = 0; index < 2; ++index) {
            for (int i = 0; i < n; ++i) {
                string tp; int x;
                tie(tp, x) = commands[i];
                x = (x >> bit) & 1;
                if (tp == "&") f[index] &= x;
                if (tp == "|") f[index] |= x;
                if (tp == "^") f[index] ^= x;
            }
        }
        if (f == vector<int>{0, 0}) {
            ansand ^= 1 << bit;
        } else if (f == vector<int>{1, 0}) {
            ansxor ^= 1 << bit;
        } else if (f == vector<int>{1, 1}) {
            ansor ^= 1 << bit;
        }
    }
    cout << 3 << endl;
    cout << "^ " << ansxor << endl;
    cout << "& " << ansand << endl;
    cout << "| " << ansor << endl;
}