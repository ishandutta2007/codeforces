#include <bits/stdc++.h>

const int N = 500005;

bool in[N], era[N];

int n, m, h, Ans, pt;
int a[N], b[N], c[N], d[N], ord[N];

std::set<std::pair<std::pair<int, int>, int> > s;

bool cmp(int x, int y) { return b[x] < b[y]; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i] >> b[i];
        ord[i] = i, c[i] = std::max(a[i], b[i]);
        d[i] = a[i] + b[i];
        s.insert(std::make_pair(std::make_pair(c[i], d[i]), i));
    }
    std::sort(ord + 1, ord + 1 + n, cmp);
    pt = 1;
    while (true) {
        while (pt <= n && b[ord[pt]] <= h) {
            if (a[ord[pt]] >= h) in[ord[pt]] = true;
            if (!era[ord[pt]]) s.erase(std::make_pair(std::make_pair(c[ord[pt]], d[ord[pt]]), ord[pt]));
            pt++;
        }
        bool f = false;
        while (!s.empty()) {
            int x = (*s.begin()).second;
            if (a[x] < h) {
                era[x] = true;
                s.erase(s.begin());
                continue;
            }
            f = true;
            in[x] = true;
            h = b[x];
            break;
        }
        if (!f) break;
    }
    for (int i = 1; i <= n; ++i) Ans += in[i];
    std::cout << Ans << '\n';
    return 0;
}