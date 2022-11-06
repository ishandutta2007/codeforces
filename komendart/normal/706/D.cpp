#include <bits/stdc++.h>

using namespace std;

const int maxw = 1e7;

int last = 1;
int go[maxw][2];
int cnt[maxw];

void add(int x) {
    int node = 0;
    for (int i = 31; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (!go[node][c]) {
            go[node][c] = last;
            last++;
        }
        node = go[node][c];
        cnt[node]++;
    }
}

void del(int x) {
    int node = 0;
    for (int i = 31; i >= 0; i--) {
        int c = (x >> i) & 1;
        node = go[node][c];
        cnt[node]--;
    }
}

int get(int x) {
    int node = 0;
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        int c = (x >> i) & 1;
        c ^= 1;
        if (go[node][c] && cnt[go[node][c]]) {
            ans ^= 1 << i;
            node = go[node][c];
        } else {
            node = go[node][c ^ 1];
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    add(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string tp; int x;
        cin >> tp >> x;
        if (tp == "+") add(x);
        else if (tp == "-") del(x);
        else cout << get(x) << '\n';
    }
}