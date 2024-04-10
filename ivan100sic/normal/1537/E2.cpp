// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct substring_compare {
    vector<vector<int>> cc;

    int re(int x, int n) { return x >= n ? x - n : x; }

    substring_compare(const string& s) {
        int n = s.size(), sz = 0;
        vector<int> c(begin(s), end(s)), p(n);
        vector<vector<int>> g(max(n, 128));
        for (int i=0; i<n; i++) {
            g[c[i]].push_back(i);
        }
        for (auto& gr : g) {
            for (int i : gr) {
                p[sz++] = i;
            }
            gr.clear();
        }
        for (int h=1; h<n; h*=2) {
            cc.push_back(c);
            vector<int> pn(n), cn(n);
            for (int j : p) {
                int jp = re(j+n-h, n);
                g[c[jp]].push_back(jp);
            }
            sz = 0;
            for (auto& gr : g) {
                for (int i : gr) {
                    pn[sz++] = i;
                }
                gr.clear();
            }
            cn[pn[0]] = 0;
            int nc = 1;
            for (int i=1; i<n; i++) {
                int s0 = pn[i-1], s1 = pn[i];
                if (c[s1] == c[s0] && c[re(s1+h, n)] == c[re(s0+h, n)]) {
                    cn[s1] = nc - 1;
                } else {
                    cn[s1] = nc++;
                }
            }
            swap(c, cn);
            swap(p, pn);
        }
    }

    struct substring {
        substring_compare* ctx;
        int l, r;

        int cmp(const substring& o) const {
            int tw = r - l, ow = o.r - o.l, tl = l, ol = o.l;
            int w = min(tw, ow);
            for (size_t i=0; i<ctx->cc.size(); i++) {
                if (w & (1 << i)) {
                    if (int d = ctx->cc[i][tl] - ctx->cc[i][ol]; d) {
                        return d; 
                    }
                    tl += 1 << i;
                    ol += 1 << i;
                }
            }
            return tw - ow;
        }

        bool operator< (const substring& o) const {
            return cmp(o) < 0;
        }

        bool operator== (const substring& o) const {
            return cmp(o) == 0;
        }
    };

    substring operator() (int l, int r) {
        return {this, l, r};
    }
};

string brut(string s, int k) {
    int n = s.size();
    string z = "\x7f";
    for (int i=1; i<=n; i++) {
        string t;
        for (int j=0; j<k; j++) {
            t += s[j%i];
        }
        z = min(z, t);
    }
    return z;
}

string prosiri(string s, int k) {
    string t;
    for (int i = 0; i < k; i++) {
        t += s[i % s.size()];
    }
    return t;
}

string najbolji(string s) {
    vector<int> a(s.size());
    substring_compare co(s);
    iota(begin(a), end(a), 1);
    auto cmp = [&](int i, int j) {
        int s = 1, d = 0;
        if (i == j) return false;
        if (i > j) {
            s = -1;
            swap(i, j);
        }

        if (j-i < i) {
            int t = co(0, j-i).cmp(co(i, j));
            if (t) {
                d = t;
            } else {
                t = co(j-i, i).cmp(co(0, 2*i-j));
                if (t) {
                    d = t;
                } else {
                    d = co(i, j).cmp(co(2*i-j, i));
                }
            }
        } else {
            int t = co(0, i).cmp(co(i, 2*i));
            if (t) {
                d = t;
            } else {
                t = co(i, j-i).cmp(co(2*i, j));
                if (t) {
                    d = t;
                } else {
                    d = co(j-i, j).cmp(co(0, i));
                }
            }
        }
        
        return d*s < 0;
    };

    return s.substr(0, *min_element(begin(a), end(a), cmp));
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << prosiri(najbolji(s), k) << '\n';
}