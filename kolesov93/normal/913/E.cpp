#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
typedef pair<int, int> pii;

const int N = 8;
string ans[1 << N][4]; // 0 - no op, 1 - nots, 2 - ands, 3 - ors
bool used[1 << N][4];

vector<pii> done;
vector<pii> ready;

bool better(const string& a, const string& b) {
    return a.size() < b.size() || (a.size() == b.size() && a < b);
}

void update(int mask, int ops, string&& value) {
    if (ans[mask][ops].size() == 0 || better(value, ans[mask][ops])) {
        ans[mask][ops] = value;
        if (!used[mask][ops]) {
            used[mask][ops] = true;
            ready.emplace_back(mask, ops);
        }
    }
}

int main() {
    int sx = 0, sy = 0, sz = 0;
    for (int msk = 0; msk < 8; ++msk) {
        if (msk & 1) sz += (1 << msk);
        if (msk & 2) sy += (1 << msk);
        if (msk & 4) sx += (1 << msk);
    }
    update(sx, 0, "x");
    update(sy, 0, "y");
    update(sz, 0, "z");

    ready.emplace_back(sx, 0);
    ready.emplace_back(sy, 0);
    ready.emplace_back(sz, 0);
    while (!ready.empty()) {
        int best = 0;
        for (size_t i = 1; i < ready.size(); ++i) {
            if (better(ans[ready[i].first][ready[i].second], ans[ready[best].first][ready[best].second])) {
                best = i;
            }
        }

        auto current = ready[best];
        done.push_back(current);
        ready[best] = ready[int(ready.size()) - 1];
        ready.pop_back();

        update(255 ^ current.first, max(1, current.second), current.second <= 1 ? "!" + ans[current.first][current.second] : "!(" + ans[current.first][current.second] + ")");
        for (auto&& lhsi : done) {
            auto lhs = lhsi.second > 3 ? "(" + ans[lhsi.first][lhsi.second] + ")" : ans[lhsi.first][lhsi.second];
            auto rhs = current.second > 3 ? "(" + ans[current.first][current.second] + ")" : ans[current.first][current.second];
            update(lhsi.first | current.first, 3, lhs + "|" + rhs);
            update(lhsi.first | current.first, 3, rhs + "|" + lhs);

            lhs = lhsi.second > 2 ? "(" + ans[lhsi.first][lhsi.second] + ")" : ans[lhsi.first][lhsi.second];
            rhs = current.second > 2 ? "(" + ans[current.first][current.second] + ")" : ans[current.first][current.second];
            update(lhsi.first & current.first, max(max(lhsi.second, current.second), 2), lhs + "&" + rhs);
            update(lhsi.first & current.first, max(max(lhsi.second, current.second), 2), rhs + "&" + lhs);
        }
    }

    map<string, string> result;
    for (int msk = 0; msk < (1 << 8); ++msk) {
        int best = -1;
        for (int i = 0; i < 4; ++i) {
            if (ans[msk][i].size() == 0) continue;
            if (best == -1 || better(ans[msk][i], ans[msk][best])) {
                best = i;
            }
        }
        string mask;
        for (int i = 0; i < 8; ++i) {
            if (msk & (1 << i)) {
                mask += "1";
            } else {
                mask += "0";
            }
        }
        result[mask] = ans[msk][best];
    }

    int n;
    cin >> n;
    while (n--) {
        string w; cin >> w;
        cout << result[w] << "\n";
    }


    return 0;
}