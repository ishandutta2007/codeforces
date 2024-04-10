#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct node {
    int to[2];
    vector<int> vct;
    vector<int> arrows[2];
    node() {
        to[0] = to[1] = -1;
    }
};

const int rmax = 29;
vector<node> nodes;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void add(int val, int i) {
    int v = 0;
    for (int r = rmax; r >= 0; --r) {
        int b = bit(val, r);
        if (nodes[v].to[b] == -1) {
            nodes.pb(node());
            nodes[v].to[b] = sz(nodes) - 1;
        }
        v = nodes[v].to[b];
    }
    nodes[v].vct.pb(i);
}

void unite(int v) {
    if (nodes[v].to[0] == -1 && nodes[v].to[1] == -1) {
        return;
    }
    for (int b = 0; b < 2; ++b) {
        if (nodes[v].to[b] != -1) {
            unite(nodes[v].to[b]);
        }
    }
    for (int b = 0; b < 2; ++b) {
        if (nodes[v].to[b ^ 1] == -1) {
            nodes[v].vct = nodes[nodes[v].to[b]].vct;
            for (int i = 0; i < sz(nodes[v].vct); ++i) {
                nodes[v].arrows[b].pb(i);
            }
            return;
        }
    }

    vector<int>& a = nodes[nodes[v].to[0]].vct;
    vector<int>& b = nodes[nodes[v].to[1]].vct;
    int i = 0, j = 0;
    while (i < sz(a) && j < sz(b)) {
        if (a[i] < b[j]) {
            nodes[v].vct.pb(a[i]);
            nodes[v].arrows[0].pb(i);
            nodes[v].arrows[1].pb(j);
            ++i;
        } else {
            nodes[v].vct.pb(b[j]);
            nodes[v].arrows[1].pb(j);
            nodes[v].arrows[0].pb(i);
            ++j;
        }
    }
    while (i < sz(a)) {
        nodes[v].vct.pb(a[i]);
        nodes[v].arrows[0].pb(i);
        nodes[v].arrows[1].pb(sz(b));
        ++i;
    }
    while (j < sz(b)) {
        nodes[v].vct.pb(b[j]);
        nodes[v].arrows[1].pb(j);
        nodes[v].arrows[0].pb(sz(a));
        ++j;
    }
}

const int inf = 1073741824;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        nodes.clear();
        int n;
        cin >> n;
        nodes.pb(node());
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            add(a[i], i);
        }
        unite(0);

        /*for (int v = 0; v < sz(nodes); ++v) {
            cout << "! " << v << ": ";
            for (int x : nodes[v].vct) {
                cout << x << " ";
            }
            cout << "\n";
        }*/

        int q;
        cin >> q;

        while (q--) {
            int L, R;
            cin >> L >> R;
            --L, --R;
            int v = 0;
            int i = L;
            int j = R;
            int ans = 0;
            vector<int> extra;
            vector<int> pos;
            for (int r = rmax; r >= 0; --r) {
                if (i == j) {
                    for (int z : pos) {
                        if (nodes[v].vct[i] != z) {
                            extra.pb(a[nodes[v].vct[i]] | a[z]);
                        }
                    }
                    ans = inf;
                    break;
                }
                int son = nodes[v].to[0];
                /*cout << "! " << r << ": ";

                for (int x : nodes[v].vct) {
                    cout << x << " ";
                }
                cout << endl;*/
                int att = -1;
                if (son != -1) {
                    int ni = nodes[v].arrows[0][i];
                    int nj = nodes[v].arrows[0][j];
                    if (nj >= sz(nodes[son].vct) || nodes[son].vct[nj] > R) {
                        --nj;
                    }
                    if (ni <= nj) {
                        if (ni < nj) {
                            i = ni, j = nj;
                            v = son;
                            continue;
                        } else {
                            pos.pb(nodes[son].vct[ni]);
                            for (int z : pos) {
                                if (nodes[son].vct[ni] != z) {
                                    extra.pb(a[nodes[son].vct[ni]] | a[z]);
                                }
                            }
                        }
                    }
                }

                ans |= (1 << r);
                son = nodes[v].to[1];
                if (son == -1) {
                    break;
                }
                int ni = nodes[v].arrows[1][i];
                int nj = nodes[v].arrows[1][j];
                if (nj >= sz(nodes[son].vct) || nodes[son].vct[nj] > R) {
                    --nj;
                }
                i = ni, j = nj;
                if (att != -1) {
                    pos.pb(att);
                }

                v = son;
            }
            for (int x : extra) {
                ans = min(ans, x);
            }
            cout << ans << "\n";
        }
    }

}