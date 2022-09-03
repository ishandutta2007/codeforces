#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


constexpr lint INF = 1e18 + 10;
int main()
{
    int N;
    lint P;
    cin >> N >> P;

    priority_queue<lint, vector<plint>, greater<plint>> pq;
    set<lint> TS{INF};
    REP(i, N)
    {
        lint t;
        cin >> t;
        pq.emplace(t, i);
        TS.insert(t);
    }

    set<int> awake;
    vector<lint> ret(N);

    set<int> vacant{N};
    deque<plint> waiting; // (person, end_time)

    lint now = 0;

    int calculated = 0;

    while (calculated < N)
    {
        if (!pq.empty() and pq.top().first <= now)
        {
            awake.insert(pq.top().second);
            pq.pop();
            continue;
        }

        if (!waiting.empty() and waiting.front().second <= now)
        {
            ret[waiting.front().first] = now;
            calculated++;
            vacant.erase(waiting.front().first);
            waiting.pop_front();
            continue;
        }

        if (!awake.empty() and *awake.begin() < *vacant.begin())
        {
            lint tfinish = now + P;
            int person = *awake.begin();
            if (!waiting.empty()) tfinish = waiting.back().second + P;
            TS.insert(tfinish);

            waiting.emplace_back(person, tfinish);
            vacant.insert(person);

            awake.erase(person);
            continue;
        }

        now = *TS.upper_bound(now);
    }

    REP(i, N) printf("%lld ", ret[i]);
    puts("");
}