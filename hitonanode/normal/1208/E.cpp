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
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N, W;
    cin >> N >> W;
    vector<lint> rimos(W + 10);
    REP(_, N)
    {
        int L;
        cin >> L;
        vector<int> A(L);
        cin >> A;
        if (L * 2 <= W)
        {
            int maxi = 0;
            REP(i, L)
            {
                mmax(maxi, A[i]);
                rimos[i] += maxi, rimos[i + 1] -= maxi;
            }
            maxi = 0;
            REP(i, L)
            {
                mmax(maxi, A[L - 1 - i]);
                rimos[W - 1 - i] += maxi, rimos[W - i] -= maxi;
            }
            rimos[L] += maxi, rimos[W - L] -= maxi;
        }
        else
        {
            queue<int> choice;
            multiset<int> se;
            REP(i, W)
            {
                if (i < L) choice.push(A[i]), se.insert(A[i]);
                if (i > W - L)
                {
                    se.erase(se.lower_bound(choice.front()));
                    choice.pop();
                }
                int addv = *prev(se.end());
                if (i < W - L or i >= L) mmax(addv, 0);
                rimos[i] += addv, rimos[i + 1] -= addv;
            }
        }
    }
    REP(i, W) rimos[i + 1] += rimos[i];
    REP(i, W) printf("%lld ", rimos[i]);
    puts("");
}