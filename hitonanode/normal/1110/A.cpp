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

const string EVEN = "even";
const string ODD = "odd";

int main()
{
    int B, K;
    cin >> B >> K;
    vector<int> A(K);
    cin >> A;
    if (B % 2 == 0)
    {
        cout << (A.back() % 2 ? ODD : EVEN) << endl;
    }
    else
    {
        cout << (accumulate(ALL(A), 0) % 2 ? ODD : EVEN) << endl;
    }
}