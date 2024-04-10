// :)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
constexpr int SIZE = 300;
int n, cnt;
std::vector<int> a, pos, ltag, rtag, l, r, lp, rp, atag, temp1, temp2;
std::vector<std::vector<int>> sl, sr;
long long ans;
void rebuild(int b) {
    for (int i = b * SIZE; i < std::min(n, (b + 1) * SIZE); ++i) {
        if (l[i] == r[i])
            continue;
        l[i] = std::max(l[i] + atag[b], ltag[b]);
        r[i] = std::min(r[i] + atag[b], rtag[b]);
    }
    ltag[b] = -1;
    rtag[b] = n;
    atag[b] = 0;
    lp[b] = rp[b] = sr[b].size() + 1;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    pos.resize(n);
    cnt = (n + SIZE - 1) / SIZE;
    l.resize(n);
    r.resize(n);
    ltag.assign(cnt, -1);
    rtag.assign(cnt, n);
    atag.resize(cnt);
    sl.resize(cnt);
    sr.resize(cnt);
    lp.resize(cnt);
    rp.resize(cnt);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        int b = pos[i] / SIZE;
        rebuild(b);
        int rpos = 0;
        for (int j = 0; j < b; ++j)
            rpos += sl[j].size();
        for (int j = b * SIZE; j < pos[i]; ++j)
            if (l[j] != r[j])
                ++rpos;
        l[pos[i]] = -1;
        r[pos[i]] = i + 1;
        ans += i + 1;
        for (int j = b * SIZE; j < pos[i]; ++j) {
            if (l[j] == r[j])
                continue;
            if (r[j] > rpos) {
                ans -= r[j] - rpos;
                r[j] = rpos;
            }
        }
        for (int j = pos[i] + 1; j < std::min(n, (b + 1) * SIZE); ++j) {
            if (l[j] == r[j])
                continue;
            ++l[j];
            ++r[j];
            if (l[j] < rpos) {
                ans -= rpos - l[j];
                l[j] = rpos;
            }
        }
        temp1.clear();
        temp2.clear();
        for (int j : sr[b]) {
            if (j < pos[i]) {
                temp1.push_back(j);
            } else {
                temp2.push_back(j);
            }
        }
        std::merge(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), sr[b].begin(), [&](int i, int j) {
            return r[i] < r[j];
        });
        temp1.clear();
        temp2.clear();
        for (int j : sl[b]) {
            if (j < pos[i]) {
                temp1.push_back(j);
            } else {
                temp2.push_back(j);
            }
        }
        std::merge(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), sl[b].begin(), [&](int i, int j) {
            return l[i] >l[j];
        });
        sl[b].push_back(pos[i]);
        sr[b].push_back(pos[i]);
        for (int j = 0; j < b; ++j) {
            if (rpos >= rtag[j])
                continue;
            ans -= 1LL * (sr[j].size() - rp[j]) * (rtag[j] - rpos);
            while (rp[j] > 0 && r[sr[j][rp[j] - 1]] + atag[j] > rpos) {
                ans -= r[sr[j][rp[j] - 1]] + atag[j] - rpos;
                --rp[j];
            }
            rtag[j] = rpos;
        }
        for (int j = b + 1; j < cnt; ++j) {
            ++atag[j];
            ++ltag[j];
            ++rtag[j];
            if (rpos <= ltag[j])
                continue;
            ans -= 1LL * (sl[j].size() - lp[j]) * (rpos - ltag[j]);
            while (lp[j] > 0 && l[sl[j][lp[j] - 1]] + atag[j] < rpos) {
                ans -= rpos - (l[sl[j][lp[j] - 1]] + atag[j]);
                --lp[j];
            }
            ltag[j] = rpos;
        }
        std::cout << ans << "\n";
    }
    return 0;
}