#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
constexpr long long P = 1'000'000'000'000'000'000;
long long ansH, ansL;
int ans26, ansB;
int n;
std::string s;
char c;
std::vector<int> anc, nxt, w, stk{0};
std::map<int, int> cnt;
void print() {
    if (ansH == 0) {
        std::cout << ansL << "\n";
        return;
    }
    std::cout << ansH << std::setw(18) << std::setfill('0') << ansL << "\n";
}
int query(int pos) {
    return w[*std::lower_bound(stk.begin(), stk.end(), pos)];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    anc.resize(n + 1);
    nxt.resize(n + 1);
    w.resize(n);
    std::cin >> c >> w[0];
    s += c;
    ans26 = w[0] % 26;
    ansL = ansB = w[0];
    print();
    long long sum = 0;
    for (int i = 1, j = 0; i < n; ++i) {
        std::cin >> c >> w[i];
        c = (c - 'a' + ans26) % 26 + 'a';
        s += c;
        w[i] ^= ansB;
        while (j > 0 && c != s[j])
            j = nxt[j];
        if (c == s[j])
            ++j;
        nxt[i + 1] = j;
        if (c == s[nxt[i]]) {
            anc[i] = anc[nxt[i]];
        } else {
            anc[i] = nxt[i];
        }
        for (int k = i; k > 0; ) {
            if (s[k] == c) {
                k = anc[k];
            } else {
                int v = query(i - k);
                --cnt[v];
                sum -= v;
                if (cnt[v] == 0)
                    cnt.erase(v);
                k = nxt[k];
            }
        }
        if (s[0] == c) {
            ++cnt[w[i]];
            sum += w[i];
        }
        while (!stk.empty() && w[i] <= w[stk.back()])
            stk.pop_back();
        stk.push_back(i);
        int nw = 0;
        for (auto it = cnt.upper_bound(w[i]); it != cnt.end(); ) {
            sum -= 1LL * (it -> first - w[i]) * it -> second;
            nw += it -> second;
            auto j = std::next(it);
            cnt.erase(it);
            it = j;
        }
        cnt[w[i]] += nw;
        long long res = w[stk[0]] + sum;
        ansL += res;
        if (ansL >= P) {
            ansL -= P;
            ++ansH;
        }
        ans26 = (ans26 + res) % 26;
        ansB = (ansB + res) & ((1 << 30) - 1);
        print();
    }
    return 0;
}