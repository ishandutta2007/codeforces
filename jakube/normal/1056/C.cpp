#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> used;
vector<int> p;
vector<pair<int, int>> ab;

void do_turn() {
    for (auto [a, b] : ab) {
        int x = used[a] + used[b];
        if (x == 1) {
            if (used[a]) {
                used[b] = true;
                cout << b + 1 << endl;
            } else {
                used[a] = true;
                cout << a + 1 << endl;
            }
            return;
        }
    }

    for (auto [a, b] : ab) {
        int x = used[a] + used[b];
        if (x == 0) {
            if (p[a] <= p[b]) {
                used[b] = true;
                cout << b + 1 << endl;
            } else {
                used[a] = true;
                cout << a + 1 << endl;
            }
            return;
        }
    }

    int best = -1;
    for (int i = 0; i < 2*n; i++) {
        if (used[i])
            continue;
        if (best == -1 || p[best] < p[i])
            best = i;
    }

    if (best == -1)
        exit(0);

    cout << best + 1 << endl;
    used[best] = true;
}

int main() {
    cin >> n >> m;
    p.resize(2*n);
    for (auto& x : p)
        cin >> x;
    
    ab.resize(m);
    for (auto& x : ab) {
        cin >> x.first >> x.second;
        x.first--;
        x.second--;
    }

    used.assign(2*n, false);

    int t;
    cin >> t;
    
    if (t == 1)
        do_turn();
    
    int turns = t == 1;
    while (turns < 2 * n) {
        int x;
        cin >> x;
        x--;
        used[x] = true;
        do_turn();
        turns += 2;
    }
}