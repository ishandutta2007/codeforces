#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


struct node {
    int v1 = 0;
    int v2 = 0;
    int v3 = 0;
    int v12 = 0;
    int v23 = 0;
    int vall = 0;
    int ans() const {
        int x = 998244353;
        x = min(x, v1);
        x = min(x, v2);
        x = min(x, v3);
        x = min(x, v12);
        x = min(x, v23);
        x = min(x, vall);
        return x;
    }
};

void update(node& a, node& b, node& c) {
    a.v1 = b.v1 + c.v1;
    a.v2 = b.v2 + c.v2;
    a.v3 = b.v3 + c.v3;
    a.v12 = min(b.v12 + c.v2, b.v1 + c.v12);
    a.v23 = min(b.v23 + c.v3, b.v2 + c.v23);
    a.vall = min(b.v1 + c.vall, min(b.v12 + c.v23, b.vall + c.v3));
}

void set_char(node& a, char c) {
    a.v1 = (c == 'a' ? 1 : 0);
    a.v2 = (c == 'b' ? 1 : 0);
    a.v3 = (c == 'c' ? 1 : 0);
    a.v12 = (c != 'a' ? 1 : 0);
    a.v23 = (c != 'b' ? 1 : 0);
    a.vall = 0;
}

const int MAXN = (1 << 17);
node tree[MAXN * 2 + 5];

void output() {
    for (int j = 1; j < 2 * MAXN; ++j) {
        if ((j & (j - 1)) == 0) {
            cout << endl;
        }
        cout << j;
        cout << "\t" << tree[j].v1;
        cout << "\t" << tree[j].v2;
        cout << "\t" << tree[j].v3;
        cout << "\t" << tree[j].v12;
        cout << "\t" << tree[j].v23;
        cout << "\t" << tree[j].vall;
        cout << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        set_char(tree[i + MAXN], s[i]);
    }
    for (int i = MAXN - 1; i > 0; --i) {
        update(tree[i], tree[i * 2], tree[i * 2 + 1]);
    }
//    output();
    for (int i = 0; i < q; ++i) {
        int idx;
        string t;
        cin >> idx >> t;
        --idx;
        set_char(tree[idx + MAXN], t[0]);
        for (int j = (idx + MAXN) / 2; j; j /= 2) {
            update(tree[j], tree[j * 2], tree[j * 2 + 1]);
        }
        cout << tree[1].ans() << '\n';
//        output();
    }
    
    
}