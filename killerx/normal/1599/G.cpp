#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, K;
int x[mxn], y[mxn];
int id[mxn];
int out;

std::vector <int> vec;

void add(int id) {
    vec.push_back(id);
}

void uniq() {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

std::set <std::pair <int, int> > must;

double solve() {
    std::sort(vec.begin(), vec.end());
    double ans = 1e18;
    do {
        if (vec[0] != K) continue;
        double cur = 0;
        std::set <std::pair <int, int> > done;
        rep(i, (int) vec.size() - 1) {
            done.insert({vec[i], vec[i + 1]});
            done.insert({vec[i + 1], vec[i]});
            cur += std::sqrt(
                1LL * (x[vec[i + 1]] - x[vec[i]]) * (x[vec[i + 1]] - x[vec[i]]) +
                1LL * (y[vec[i + 1]] - y[vec[i]]) * (y[vec[i + 1]] - y[vec[i]]));
        }
        bool ok = true;
        for (auto pr : must) if (done.find(pr) == done.end()) {
            ok = false;
            break;
        }
        if (!ok) continue;
        ans = std::min(ans, cur);
    } while (std::next_permutation(vec.begin(), vec.end()));
    return ans;
}

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    scanf("%d %d", &n, &K);
    rep(i, n) scanf("%d %d", &x[i], &y[i]);
    -- K;
    std::map <std::pair <int, int>, std::vector <int> > map;
    rep(i, n) if (i) {
        int dx = x[i] - x[0], dy = y[i] - y[0];
        if (dx < 0 || (dx == 0 && dy < 0)) dx *= -1, dy *= -1;
        int g = gcd(std::abs(dx), std::abs(dy));
        dx /= g, dy /= g;
        map[{dx, dy}].push_back(i);
    }
    if (map.size() == 2) {
        if (map.begin()->second.size() == 1) out = map.begin()->second[0];
        else out = map.rbegin()->second[0];
    } else {
        out = 0;
    }
    std::vector <int> ids;
    rep(i, n) if (i != out) {
        ids.push_back(i);
    }
    std::sort(ids.begin(), ids.end(), [&] (int a, int b) {
        return std::make_pair(x[a], y[a]) < std::make_pair(x[b], y[b]);
    });
    long long mn = 1LL << 60;
    int mnp = -1;
    rep(xx, ids.size()) {
        int i = ids[xx];
        long long d = 1LL * (x[i] - x[out]) * (x[i] - x[out]) + 1LL * (y[i] - y[out]) * (y[i] - y[out]);
        if (d < mn) mn = d, mnp = xx;
    }
    for (int s = mnp - 1; s <= mnp + 1; ++ s) {
        if (0 <= s && s < (int) ids.size()) {
            add(ids[s]);
        }
    }
    if (K != out) {
        int p = 0;
        while (ids[p] != K) ++ p;
        add(K);
        if (p > 0) add(ids[p - 1]);
        if (p + 1 < (int) ids.size()) add(ids[p + 1]);
    }
    add(ids[0]);
    add(ids.back());
    uniq();
    std::vector <int> ovo;
    static int pos[mxn];
    rep(i, ids.size()) pos[ids[i]] = i;
    rep(i, vec.size()) ovo.push_back(pos[vec[i]]);
    std::sort(ovo.begin(), ovo.end());
    rep(i, (int) ovo.size() - 1) {
        int a = ids[ovo[i]], b = ids[ovo[i + 1]];
        if (ovo[i] + 1 < ovo[i + 1]) {
            must.insert({a, b});
            must.insert({b, a});
        }
    }
    add(out);
    printf("%.10lf\n", solve());
    return 0;
}