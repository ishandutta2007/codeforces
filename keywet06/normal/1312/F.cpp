#include <bits/stdc++.h>

int n, tmp;
int att[3];

std::vector<long long> a;
std::vector<std::vector<int>> sg, part;
std::map<std::vector<std::vector<int>>, int> s;

void update(int x) {
    for (int j = 0; j < 3; ++j) {
        bool v[4] = {};
        for (int k = 0; k < 3; ++k)
            if (k == 0 || k != j) v[sg[std::max(0, x - att[k])][k]] = true;
        while (v[sg[x][j]]) ++sg[x][j];
    }
}

int get(long long x, int i) {
    if (x >= int(sg.size())) x -= ((x - sg.size()) / tmp + 1) * tmp;
    return sg[x][i];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < 3; ++i) std::cin >> att[i];
        s.clear();
        sg.assign(5, std::vector<int>(3));
        for (int i = 1; i < 5; ++i) update(i);
        part = sg;
        while (!s.count(part)) {
            int x = sg.size();
            s[part] = x - 5;
            sg.emplace_back(3);
            update(x);
            part.push_back(sg.back());
            part.erase(part.begin());
        }
        tmp = s.size() - s[part];
        a.resize(n);
        int x = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            x ^= get(a[i], 0);
        }
        for (int i = 0; i < n; ++i) {
            int v = get(a[i], 0);
            for (int j = 0; j < 3; ++j)
                ans += (x ^ v ^ get(std::max(0ll, a[i] - att[j]), j)) == 0;
        }
        std::cout << ans << "\n";
    }
    return 0;
}