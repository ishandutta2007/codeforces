#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int solve(int N, vector<int> P)
{
    if (N <= 2) {
        return N;
    }
    set<int> s;
    for (auto x : P) s.insert(x);
    int ne = 0, no = 0;
    FOR(i, 1, N + 1) if (!s.count(i)) (i % 2 ? no : ne)++;

    vector<int> re, ro;
    vector<int> end_e, end_o;
    int l = -1;
    int cost = 0;
    REP(r, N + 1) {
        if (r == N) {
            (P[l] % 2 ? end_o : end_e).push_back(r - l - 1);
            continue;
        }
        if (!P[r]) continue;

        if (l == -1) {
            (P[r] % 2 ? end_o : end_e).push_back(r - l - 1);
        }
        else if (P[r] % 2 == P[l] % 2) {
            (P[r] % 2 ? ro : re).push_back(r - l - 1);
        }
        else cost++;

        l = r;
    }
    sort(ALL(re));
    sort(ALL(ro));
    sort(ALL(end_o));
    sort(ALL(end_e));
    for (auto x : re) {
        if (ne >= x) ne -= x;
        else cost += 2;
    }
    for (auto x : end_e) {
        if (ne >= x) ne -= x;
        else cost += 1;
    }
    for (auto x : ro) {
        if (no >= x) no -= x;
        else cost += 2;
    }
    for (auto x : end_o) {
        if (no >= x) no -= x;
        else cost += 1;
    }
    return cost;
}

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    cin >> P;
    if (N <= 2) {
        cout << N - 1 << endl;
        return 0;
    }
    map<int, int> s;
    for (auto x : P) s[x]++;

    if (s.size() == 1) {
        cout << 1 << endl;
        return 0;
    }

    int tmp = solve(N, P);
    cout << tmp << endl;
}