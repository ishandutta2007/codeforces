#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

class UnionFind {
    public:
        vector<int> par;

        UnionFind(int n) {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
        }

        int find(int x) {
            return par[x] == x ? x : par[x] = find(par[x]);
        }

        void do_union(int x, int y) {
            int a = find(x);
            int b = find(y);

            if (a != b) {
                par[a] = b;
            }
        }
};

int leading(unsigned int x) {
    return 32 - __builtin_clz(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    adj.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> forbiddens(n);
    // vector<int> last(n, 0);
    vector<int> forbidden(n, 0);
    vector<int> missing(n);

    vector<int> result(n, 0);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1)
            q.push_back(i);
        missing[i] = adj[i].size();
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop_front();
        int forb = forbidden[idx];

        int mx = 26;
        while (mx > -1) {
            int cnt = 0;
            int y = 1 << mx;
            for (int f : forbiddens[idx]) {
                if (f & y)
                    cnt++;
            }

            if (cnt > 1) {
                break;
            }
            mx--;
        }

        for (int i = mx + 1; i < 26; i++) {
            if (!(forb & (1 << i))) {
                result[idx] = i+1;
                break;
            }
        }
        
        if (result[idx] == 0) {
            cout << "Impossible!" << endl;
            return 0;
        }

        int x = ~((1 << (result[idx] - 1)) - 1);
        x &= forb;
        x |= 1 << (result[idx] - 1);

        for (int next : adj[idx]) {
            if (result[next] == 0) {
                forbidden[next] |= x;
                forbiddens[next].push_back(x);
                missing[next]--;
                if (missing[next] == 1) {
                    q.push_back(next);
                }
            }
        }
    }

    for (int i : result) {
        cout << (char)('A' + (26 - i)) << ' ';
    }
    cout << endl;


    return 0;
}