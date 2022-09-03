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


int N, M;
vector<int> C;
constexpr lint MOD = 998244353;

inline vector<lint> gen_new_vec(const vector<lint> &nxt_vec)
{
    vector<lint> tmp(nxt_vec.size() + 1);
    REP(j, nxt_vec.size())
    {
        tmp[j + 1] += nxt_vec[j];
        if (tmp[j + 1] >= MOD) tmp[j + 1] -= MOD;
    }
    IREP(i, tmp.size() - 1)
    {
        tmp[i] += tmp[i + 1];
        if (tmp[i] >= MOD) tmp[i] -= MOD;
    }
    tmp[0] = 0;
    return tmp;
}

inline vector<lint> merge_new_vec(const vector<lint> &v1, const vector<lint> &v2)
{
    vector<lint> ret(v1.size() + v2.size() - 1);
    REP(i, v1.size()) if (v1[i]) REP(j, v2.size()) if (v2[j])
    {
        lint t = (lint)v1[i] * v2[j] % MOD;
        (ret[i + j] +=t) %= MOD;
        if (j) (ret[j - 1] += MOD - t) %= MOD;
    }
    IREP(i, ret.size() - 1)
    {
        ret[i] += ret[i + 1];
        if (ret[i] >= MOD) ret[i] -= MOD;
    }
    ret[0] = 0;
    while (ret.size() > 1 and ret.back() == 0) ret.pop_back();
    return ret;
}

int main()
{
    cin >> N >> M;
    C.resize(N);
    REP(i, N)
    {
        cin >> C[i];
        C[i]--;
    }
    map<pint, vector<lint>> ma;
    IREP(i, N)
    {
        int pos = 0;
        while (C[pos] != i) pos++;
        pint pa(pos, pos);
        auto itr1 = ma.lower_bound(pa);
        bool nxt_use = false, prv_use = false;
        if (itr1 != ma.end() and itr1->first.first == pos + 1) nxt_use = true;
        if (itr1 != ma.begin() and prev(itr1)->first.second == pos - 1) prv_use = true;

        pint pa_nxt(pos, pos);
        if (nxt_use)
        {
            auto itr1 = ma.lower_bound(pa);
            pa_nxt.second = itr1->first.second;

            auto tmp = gen_new_vec(itr1->second);
            ma.erase(itr1);

            if (prv_use)
            {
                itr1 = prev(ma.lower_bound(pa));
                pa_nxt.first = itr1->first.first;
                // dbg(tmp);
                tmp = merge_new_vec(itr1->second, tmp);
                // dbg(tmp);
                ma.erase(itr1);
            }
            ma[pa_nxt] = tmp;
        }
        else if (prv_use)
        {
            itr1 = prev(ma.lower_bound(pa));
            pa_nxt.first = itr1->first.first;
            auto tmp = gen_new_vec(itr1->second);
            ma.erase(itr1);
            ma[pa_nxt] = tmp;
        }
        else ma[pa_nxt] = vector<lint>{0, 1};
        // dbg(ma);
    }
    cout << accumulate(ALL(ma.begin()->second), 0LL) % MOD << endl;
}