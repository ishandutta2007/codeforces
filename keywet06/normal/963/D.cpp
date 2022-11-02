#include <bits/stdc++.h>

typedef long long int64;

const int N = 100100;

int QK[N], QA[N];

int64 HN = 37, pows[N], hsh[N];

std::string s;
std::string QS[N];

std::map<int, std::vector<int> > qm;

void prec() {
    pows[0] = 1;
    for (int i = 0; i + 1 < N; ++i) {
        pows[i + 1] = pows[i] * HN;
    }
    for (int i = 0; i < s.size(); ++i) {
        hsh[i + 1] = hsh[i] * HN + s[i];
    }
}

std::unordered_map<int64, std::vector<int> > occ;
void process(int l) {
    for (int i = 0; i + l <= s.size(); ++i) {
        int64 h = hsh[i + l] - hsh[i] * pows[l];
        if (occ.find(h) != occ.end()) {
            occ[h].push_back(i);
        }
    }
}

int64 Hash(std::string &t) {
    int64 h = 0;
    for (int i = 0; i < t.size(); ++i) {
        h = h * HN + t[i];
    }
    return h;
}

int q;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    prec();
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> QK[i] >> QS[i];
        qm[QS[i].size()].push_back(i);
    }
    for (auto i = qm.begin(); i != qm.end(); ++i) {
        int l = i->first;
        std::vector<int> &qv = i->second;
        occ.clear();
        for (auto j = qv.begin(); j != qv.end(); ++j) {
            int q = *j;
            int64 h = Hash(QS[q]);
            occ[h] = std::vector<int>();
        }
        process(l);
        for (auto j = qv.begin(); j != qv.end(); ++j) {
            int q = *j;
            int64 h = Hash(QS[q]);
            std::vector<int> &o = occ[h];
            int &ans = QA[q];
            ans = N;
            for (int k = 0; k + QK[q] <= o.size(); ++k) {
                int diff = o[k + QK[q] - 1] - o[k];
                ans = std::min(ans, diff + l);
            }
            if (ans == N) ans = -1;
        }
    }
    for (int i = 0; i < q; ++i) std::cout << QA[i] << "\n";
    return 0;
}