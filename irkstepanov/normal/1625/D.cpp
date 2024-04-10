#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct node {
    int to[2];
    int id;
    node() {
        to[0] = to[1] = id = -1;
    }
};

vector<node> t;
const int rmax = 30;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void add(int x, int id) {
    int v = 0;
    for (int r = rmax; r >= 0; --r) {
        int b = bit(x, r);
        if (t[v].to[b] == -1) {
            t[v].to[b] = sz(t);
            t.pb(node());
        }
        v = t[v].to[b];
    }
    t[v].id = id;
}

void descend(int v, int cnt, vector<int>& vct) {
    if (cnt == 0) {
        vct.pb(v);
        return;
    }
    for (int i = 0; i < 2; ++i) {
        int to = t[v].to[i];
        if (to != -1) {
            descend(to, cnt - 1, vct);
        }
    }
}

int find_any(int v) {
    if (t[v].id != -1) {
        return t[v].id;
    }
    for (int i = 0; i < 2; ++i) {
        int to = t[v].to[i];
        if (to != -1) {
            return find_any(to);
        }
    }
    return -1;
}

pii solve(int u, int v, int k, int len) {
    //cout << u << " " << v << " " << len << endl;
    if (len == 0) {
        return {t[u].id, t[v].id};
    }
    if (!bit(k, len - 1)) {
        if (t[u].to[0] != -1 && t[v].to[1] != -1) {
            int x = find_any(t[u].to[0]);
            int y = find_any(t[v].to[1]);
            return {x, y};
        }
        if (t[u].to[1] != -1 && t[v].to[0] != -1) {
            int x = find_any(t[u].to[1]);
            int y = find_any(t[v].to[0]);
            return {x, y};
        }
        if (t[u].to[0] != -1 && t[v].to[0] != -1) {
            return solve(t[u].to[0], t[v].to[0], k, len - 1);
        }
        if (t[u].to[1] != -1 && t[v].to[1] != -1) {
            return solve(t[u].to[1], t[v].to[1], k, len - 1);
        }
        assert(false);
    }
    if (t[u].to[0] != -1 && t[v].to[1] != -1) {
        pii p = solve(t[u].to[0], t[v].to[1], k, len - 1);
        if (p.first != -1 && p.second != -1) {
            return p;
        }
    }
    if (t[u].to[1] != -1 && t[v].to[0] != -1) {
        pii p = solve(t[u].to[1], t[v].to[0], k, len - 1);
        if (p.first != -1 && p.second != -1) {
            return p;
        }
    }
    if (t[u].to[0] != -1) {
        int x = find_any(t[u].to[0]);
        return {x, -1};
    }
    if (t[u].to[1] != -1) {
        int x = find_any(t[u].to[1]);
        return {x, -1};
    }
    assert(false);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    t.pb(node());
    int n, k;
    cin >> n >> k;


    if (k == 0) {
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << " ";
        }
        cout << "\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(x, i);
    }

    int len = 1;
    while (k >= (1 << len)) {
        ++len;
    }

    vector<int> vct;
    descend(0, 1 + rmax - len, vct);

    vector<int> ans;
    for (int v : vct) {
        //cout << "!" << v << endl;
        if (t[v].to[0] != -1 && t[v].to[1] == -1) {
            int curr = find_any(t[v].to[0]);
            ans.pb(curr);
        } else if (t[v].to[0] == -1 && t[v].to[1] != -1) {
            int curr = find_any(t[v].to[1]);
            ans.pb(curr);
        } else {
            pii p = solve(t[v].to[0], t[v].to[1], k, len - 1);
            if (p.first != -1) {
                ans.pb(p.first);
            }
            if (p.second != -1) {
                ans.pb(p.second);
            }
        }
    }

    if (sz(ans) < 2) {
        cout << "-1\n";
        return 0;
    }
    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}