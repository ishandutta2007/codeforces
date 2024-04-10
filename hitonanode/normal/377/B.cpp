#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }


int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, M, S;
    cin >> N >> M >> S;
    vector<int> A(M), B(N), C(N);

    cin >> A >> B >> C;

    vector<tuple<int, int, int>> levelcostid;
    REP(i, N) levelcostid.emplace_back(B[i], C[i], i + 1);
    REP(q, M) levelcostid.emplace_back(A[q], -1, q);

    sort(levelcostid.rbegin(), levelcostid.rend());

    int ng = 0, ok = M + 1;
    vector<int> ret;
    while (ok - ng > 1) {
        const int day = (ok + ng) / 2;
        int hito = (N + day - 1) / day;

        priority_queue<pint, vector<pint>, greater<pint>> cost2id;
        int ncap = 0;
        int h = -2;
        bool b = true;
        vector<int> tmp(M, -1);

        long long total_cost = 0;
        for (auto [_, c, i] : levelcostid) {
            if (c >= 0) {
                cost2id.emplace(c, i);
            } else {
                if (ncap <= 0) {
                    if (cost2id.empty()) {
                        b = false;
                        break;
                    }
                    auto [c, id_] = cost2id.top();
                    cost2id.pop();
                    total_cost += c;
                    h = id_;
                    ncap += day;
                }
                ncap--;
                tmp[i] = h;
            }
        }
        if (total_cost > S) b = false;

        if (b) {
            ret = tmp;
            ok = day;
        } else {
            ng = day;
        }
    }

    if (ret.size()) {
        cout << "YES\n";
        for (auto x : ret) cout << x << ' ';
        cout << '\n';
    } else {
        puts("NO");
    }
}