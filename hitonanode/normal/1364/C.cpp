#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void NO()
{
    puts("-1");
    exit(0);
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<int> last_v(N * 2 + 2, -1);
    REP(i, N) last_v[A[i]] = i;
    vector<int> B(N);

    int h = 0;
    vector<int> in_b(N * 2 + 2);
    int anow = 0;
    REP(i, N)
    {
        if (i and last_v[A[i - 1]] == i - 1)
        {
            B[i] = A[i - 1];
        }
        else
        {
            while (last_v[h] != -1 or in_b[h]) h++;
            B[i] = h;
            h++;
        }
        in_b[B[i]] = 1;
        while (in_b[anow]) anow++;
        if (anow != A[i])
        {
            // dbg(B);
            puts("-1");
            return 0;
        }
    }
    for (auto x : B) cout << x << ' ';
    cout << '\n';
}