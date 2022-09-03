#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<vector<int>> to;

void add(int begin, int end, int l, int r, int pos, int init) {
    if (r <= begin or l >= end) return;
    if (l >= begin and r <= end) {
        to[init].push_back(pos);
        return;
    }
    add(begin, end, l, (l + r) / 2, 2 * pos + 1, init);
    add(begin, end, (l + r) / 2, r, 2 * pos + 2, init);
}

int main()
{
    int N, K, D;
    cin >> N >> K >> D;
    vector<int> A(N);
    int B = 1;
    while (B <= N + 1) B <<= 1;
    to.resize(B * 2);

    cin >> A;
    sort(A.begin(), A.end());

    REP(i, N) {
        int r = upper_bound(A.begin(), A.end(), A[i] + D) - A.begin() + 1;
        int l = i + K;
        if (l <= N and l < r) {
            add(l, r, 0, B, 0, i + B - 1);
        }
    }

    REP(i, B - 1) {
        to[i].push_back(i * 2 + 1);
        to[i].push_back(i * 2 + 2);
    }

    vector<int> reach(B * 2);
    queue<int> q;
    q.push(B - 1);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == B - 1 + N) {
            puts("YES");
            return 0;
        }
        for (auto nxt : to[now]) if (!reach[nxt]) {
            q.push(nxt);
            reach[nxt] = 1;
        }
    }
    puts("NO");
}