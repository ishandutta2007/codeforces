#include <bits/stdc++.h>

const int M = 1000111;
const int N = 205;
const int L = 2222;

int lp, ls, k;

std::string p, s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::getline(std::cin, p);
    std::getline(std::cin, s);
    std::cin >> k;
    lp = p.size(), ls = s.size();
    if (k >= lp) {
        std::vector<int> ans;
        for (int i = lp; i < k; ++i) ans.push_back(0);
        int pos = ls - 1;
        for (int i = lp - 1; i >= 0; --i) {
            if (pos < 0) {
                ans.push_back(0);
                continue;
            }
            if (p[i] == s[pos]) {
                ans.push_back(1), --pos;
            } else {
                ans.push_back(0);
            }
        }
        if (pos < 0) {
            while (ans.size() < k) ans.push_back(0);
            reverse(ans.begin(), ans.end());
            std::string r;
            r.resize(k);
            for (int i = 0; i < k; ++i) r[i] = char('0' + ans[i]);
            std::cout << r << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
        return 0;
    }
    std::string curans;
    for (int i = 0; i <= k; ++i) curans += '1';
    for (int cnt = 1; cnt <= ls; ++cnt) {
        std::vector<std::string> parts(cnt);
        int cur = 0;
        for (int i = 0; i < ls; ++i) {
            parts[cur] += s[i];
            cur = (cur + 1) % cnt;
        }
        std::vector<int> ans;
        int pos = cnt - 1;
        for (int i = k - 1; i >= 0; --i) {
            if (pos < 0) {
                ans.push_back(0);
                continue;
            }
            int len = lp / k;
            if (i < (lp % k)) ++len;
            if (len != parts[pos].size()) {
                ans.push_back(0);
                continue;
            }
            std::string result;
            int cpos = i;
            for (int j = 0; j < len; ++j) {
                result += p[cpos];
                cpos += k;
            }
            if (result == parts[pos]) {
                ans.push_back(1), --pos;
            } else {
                ans.push_back(0);
            }
        }
        if (pos < 0) {
            std::string result;
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); ++i) {
                result += char(ans[i] + '0');
            }
            if (result < curans) curans = result;
        }
    }
    if (curans.size() == k) {
        std::cout << curans << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}