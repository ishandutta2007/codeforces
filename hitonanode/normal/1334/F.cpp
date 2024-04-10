#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


// 1-indexed BIT (i : [1, len])
template<typename T>
struct BIT : std::vector<T>
{
    BIT(int len = 0) : std::vector<T>(len + 1) {}
    void reset() { fill(this->begin(), this->end(), 0); }
    void add(int pos, T v) {
        while (pos > 0 and pos < (int)this->size()) (*this)[pos] += v, pos += pos & -pos;
    }
    T sum(int pos) const { // (0, pos]
        T res = 0;
        while (pos > 0) res += (*this)[pos], pos -= pos & -pos;
        return res;
    }
    T at(int pos) const {
        return sum(pos) - sum(pos - 1);
    }
    friend std::ostream &operator<<(std::ostream &os, const BIT &bit) {
        T prv = 0;
        os << '[';
        for (int i = 1; i < (int)bit.size(); i++) {
            T now = bit.sum(i);
            os << now - prv << ",";
        }
        os << ']';
        return os;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<lint> P(N);
    cin >> A >> P;
    int M;
    cin >> M;
    vector<int> B(M);
    cin >> B;
    BIT<lint> bit(M + 2);
    bit.add(2, 1e17);
    REP(i, N)
    {
        int pp = -1;
        lint pv = 0;
        int j = lower_bound(B.begin(), B.end(), A[i]) - B.begin();

        if (j < B.size() and B[j] == A[i])
        {
            pp = j + 2;
            pv = bit.sum(j + 1);
        }

        if (P[i] >= 0)
        {
            bit.add(1, P[i]);
            bit.add(j + 2, -P[i]);
        }
        else
        {
            bit.add(1, P[i]);
        }

        if (pp != -1)
        {
            lint now = bit.sum(pp);
            if (pv < now)
            {
                bit.add(pp, pv - now);
                bit.add(pp + 1, now - pv);
            }
        }
    }

    lint ret = bit.sum(M + 1);
    if (ret > 1e16)
    {
        puts("NO");
    }
    else
    {
        puts("YES");
        printf("%lld\n", ret);
    }
}