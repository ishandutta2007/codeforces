#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int siz = 22;

int L, R;
vector < pair <pi, int> > v;

void add_edge (int a, int b, int c) {
    v.push_back({{a, b}, c});
}

void ispis () {
    cout << "YES\n";
    cout << siz + 1 << " " << v.size() << '\n';
    for (auto e : v) {
        int a = e.first.first, b = e.first.second, w = e.second;
        cout << siz + 2 - a << " " << siz + 2 - b << " " << w << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> R;
    for (int i = 2; i <= siz; i++) {
        int w = 0;
        for (int j = 1; j < i; j++) {
            add_edge(i, j, max(w, 1));
            if (w == 0) w = 1; else w *= 2;
        }
    }
    if (L == 1) {
        add_edge(siz + 1, 1, 1);
        L++;
    }
    int len = R - L + 1;
    int ofs = L - 1;
    for (int i = 0; i < 25; i++) {
        if (len & (1 << i)) {
            add_edge(siz + 1, i + 2, ofs);
            ofs += (1 << i);
        }
    }
    ispis();
    return 0;
}