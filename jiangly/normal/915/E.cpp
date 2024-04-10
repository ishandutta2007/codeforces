#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> tag, s, x;
void cover(int p, int l, int r, int v) {
    tag[p] = v;
    s[p] = v * (x[r] - x[l]);
}
void push(int p, int l, int r) {
    int m = (l + r) / 2;
    if (tag[p] != -1) {
        cover(2 * p, l, m, tag[p]);
        cover(2 * p + 1, m, r, tag[p]);
        tag[p] = -1;
    }
}
void rangeCover(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y)
        return cover(p, l, r, v);
    int m = (l + r) / 2;
    push(p, l, r);
    rangeCover(2 * p, l, m, x, y, v);
    rangeCover(2 * p + 1, m, r, x, y, v);
    s[p] = s[2 * p] + s[2 * p + 1];
}
int n, q;
std::vector<int> l, r, v;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> q;
    l.resize(q);
    r.resize(q);
    v.resize(q);
    x.reserve(2 * q + 2);
    x = {0, n};
    for (int i = 0; i < q; ++i) {
        std::cin >> l[i] >> r[i] >> v[i];
        --l[i];
        --v[i];
        x.push_back(l[i]);
        x.push_back(r[i]);
    }
    std::sort(x.begin(), x.end());
    x.erase(std::unique(x.begin(), x.end()), x.end());
    int sz = x.size() - 1;
    s.resize(4 * sz);
    tag.assign(4 * sz, -1);
    s[1] = n;
    tag[1] = 1;
    for (int i = 0; i < q; ++i) {
        l[i] = std::lower_bound(x.begin(), x.end(), l[i]) - x.begin();
        r[i] = std::lower_bound(x.begin(), x.end(), r[i]) - x.begin();
        rangeCover(1, 0, sz, l[i], r[i], v[i]);
        std::cout << s[1] << "\n";
    }
    return 0;
}