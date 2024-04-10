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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


bool solve()
{
    int N;
    cin >> N;
    priority_queue<lint, vector<lint>, greater<lint>> pq;
    REP(_, N)
    {
        int s;
        cin >> s;
        pq.push(s);
    }
    while (!pq.empty())
    {
        int a = pq.top();
        if (a == 2048) return true;
        pq.pop();
        if (pq.empty()) return false;
        if (pq.top() == a)
        {
            pq.pop();
            pq.push(a * 2);
        }
    }
    return false;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}