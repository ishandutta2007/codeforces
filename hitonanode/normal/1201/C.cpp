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



int main()
{
    lint N, K;
    cin >> N >> K;
    vector<lint> A(N);
    A.push_back(2000000001);
    cin >> A;
    sort(ALL(A));
    int i = N / 2;
    lint B = 1;
    while (i < N)
    {
        lint diff = A[i + 1] - A[i];
        lint req = diff * B;
        if (req <= K)
        {
            K -= req;
            B++;
            i++;
        }
        else
        {
            A[i] += K / B;
            K = 0;
            break;
        }
    }
    cout << A[i] << endl;
}