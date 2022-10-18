#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
    }

    int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot)
            return;

        if (rand() & 1) {
            p[xRoot] = yRoot;
        } else {
            p[yRoot] = xRoot;
        }
    }

    bool sameUnion(int x, int y) { return Find(x) == Find(y); }

    std::vector<int> p;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    long long cnt = 0;
    UnionFind uf(2*m);
    vector<int> last(m, -2);

    string s;
    for (int i = 0; i < n; i++) {
        vector<int> cur(m);
        cin >> s;
        for (int j = 0; j < m; j+=4) {
            int num = s[j/4] <= '9' ? s[j/4] - '0' : s[j/4] - 'A' + 10;
            for (int k = 0; k < 4; k++) {
                int bit = (num >> (3 - k)) & 1;
                cur[j + k] = bit ? (last[j+k] >= 0 ? last[j + k] : -1) : -2;
                // cout << bit;
            }
        }

        for (int j = 0; j + 1 < m; j++) {
            if (cur[j] >= 0 && cur[j+1] == -1) {
                cur[j+1] = cur[j];
            }
        }
        for (int j = m-1; j > 0; j--) {
            if (cur[j] >= 0 && cur[j-1] == -1) {
                cur[j-1] = cur[j];
            }
        }

        vector<bool> lastrow(2*m, false);
        for (auto x : last)
            if (x >= 0)
                lastrow[x] = true;

        int unused = 0;
        int neww = 0;
        for (int j = 0; j < m; j++) {
            if (cur[j] == -1) {
                neww++;
                while (lastrow[unused])
                    unused++;
                lastrow[unused] = true;
                cur[j] = unused;
            }
            if (j + 1 < m && cur[j] >= 0 && cur[j+1] == -1) {
                cur[j+1] = cur[j];
            }
        }

        // combine
        int unions = 0;
        // cout << "    ";
        for (int j = 0; j + 1 < m; j++) {
            if (cur[j] >= 0 && cur[j+1] >= 0 && cur[j] != cur[j+1] && !uf.sameUnion(cur[j], cur[j+1])) {
                uf.Union(cur[j], cur[j+1]);
                unions++;
            }
            // cout << cur[j] + 2;
        }
        // cout << cur.back() + 2;

        // make equal
        // cout << "    ";
        vector<bool> eraseit(2*m, false);
        for (int& xxx : cur) {
            if (xxx >= 0) {
                int p = uf.Find(xxx);
                if (p != xxx) {
                    eraseit[xxx] = true; 
                    xxx = p;
                }
            }
            // cout << xxx+2;
        }

        for (auto x : cur) {
            if (x >= 0) {
                lastrow[x] = false;
            }
        }
        
        // cnt 
        int c = 0;
        for (int j = 0; j < 2*m; j++) {
            if (lastrow[j]) {
                c++;
                uf.p[j] = j;
            }
        }

        cnt += c - unions;
        // cout << "   " << c - unions << endl;

        last = cur;
    }

    vector<bool> lastrow(2*m, false);
    for (auto x : last)
        if (x >= 0)
            lastrow[x] = true;

    int c = 0;
    for (auto b : lastrow)
        c += b;

    cnt += c;

    cout << cnt << endl;
}