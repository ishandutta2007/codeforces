#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    int N;
    cin >> N;
    map<int, vector<int>> a2t;
    vector<int> A(N), T(N);
    cin >> A >> T;
    REP(i, N) a2t[A[i]].push_back(T[i]);
    lint ret = 0;
    int now = -1;
    priority_queue<int> costs;
    lint tot_cost = 0;
    while (true) {
        if (a2t.count(now)) {
            for (auto v : a2t[now]) {
                tot_cost += v;
                costs.push(v);
            }
        }
        if (!costs.empty()) {
            tot_cost -= costs.top();
            costs.pop();
            ret += tot_cost;
            now++;
        }
        else {
            auto itr = a2t.upper_bound(now);
            if (itr == a2t.end()) break;
            else now = itr->first;
        }
    }
    cout << ret << "\n";
}