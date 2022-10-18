#include <bits/stdc++.h>
using namespace std;

std::vector<int> largest;

void computePrimesLargest(int n) {
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

std::vector<int> divisors(int x) {
    std::vector<int> d;
    d.push_back(1);

    while (x > 1) {
        int p = largest[x];
        int c = 0;
        while (largest[x] == p) {
            c++;
            x /= p;
        }
        std::vector<int> d2;
        int b = 1;
        for (int j = 0; j <= c; j++) {
            for (int x : d) {
                d2.push_back(x * b);
            }
            b *= p;
        }
        d.swap(d2);
    }
    return d;
}

struct BinaryTrie {
    BinaryTrie() {
        ch[0] = ch[1] = nullptr;
        count = 0;
    }

    void add(int val, int idx=18) {
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (!ch[c])
                ch[c] = new BinaryTrie();
            ch[c]->add(val, idx - 1);
        }
        m = min(m, val);
    }

    int find(int val, int ma, int idx=18) {
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (ch[1^c] && ch[1^c]->m <= ma)
                return ch[1^c]->find(val, ma, idx-1);
            if (ch[c] && ch[c]->m <= ma)
                return ch[c]->find(val, ma, idx-1);
            return -1;
        }
        return m;
    }

    int count;
    BinaryTrie* ch[2];
    int m = std::numeric_limits<int>::max();
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    computePrimesLargest(100'000);

    vector<BinaryTrie> bts(100'001);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int u;
            cin >> u;
            for (int d : divisors(u))
                bts[d].add(u);
        } else {
            int x, k, s;
            cin >> x >> k >> s;
            if (x % k == 0) {
                int res = bts[k].find(x, s - x);
                cout << res << '\n';
                
            } else {
                cout << -1 << '\n';
            }
        }
    }
}