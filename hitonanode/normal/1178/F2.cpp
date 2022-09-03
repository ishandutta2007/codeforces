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

template <typename T>
struct SegTree
{
    int N;
    int head;
    vector<T> x;
    T defaultT;
    using func = function<T(const T&, const T&)>;
    func merger;
    T _get(int begin, int end, int pos, int l, int r) const
    {
        if (r <= begin or l >= end) return defaultT;
        if (l >= begin and r <= end) return x[pos];
        return merger(_get(begin, end, 2 * pos + 1, l, (l + r) / 2), _get(begin, end, 2 * pos + 2, (l + r) / 2, r));
    }
    SegTree(int N, T defaultT, func merger) : N(N), defaultT(defaultT), merger(merger)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
    }
    SegTree(const vector<T> &vals, T defaultT, func merger) : N(vals.size()), defaultT(defaultT), merger(merger)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
        copy(vals.begin(), vals.end(), x.begin() + head);
        IREP(i, head) x[i] = merger(x[i * 2 + 1], x[i * 2 + 2]);
    }
    SegTree() : SegTree(0, T(), [](T, T) { return T(); }) {}
    void build(const vector<T> &vals) { copy(vals.begin(), vals.end(), x.begin() + head); IREP(i, head) x[i] = merger(x[i * 2 + 1], x[i * 2 + 2]); }
    void update(int pos, T val) { pos += head, x[pos] = val; while (pos) pos = (pos - 1) / 2, x[pos] = merger(x[pos*2+1], x[pos*2+2]); }
    T get(int begin, int end) const { return _get(begin, end, 0, 0, (int)x.size() / 2); }
    friend ostream &operator<<(ostream &os, const SegTree<T> &s) { os << "["; REP(i, s.N) os << s.get(i, i + 1) << ","; os << "]"; return os; }
};
//  NRange Maximum Query
// SegTree<int> rMq(N, 0, [](int a, int b) { return max(a, b); });


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
    SegTree<int> rmq(vector<int>(M, 0), 1, [](int a, int b) { return min(a, b); });

    vector<vector<int>> val2pos(N);
    C.resize(M);
    REP(i, M)
    {
        cin >> C[i];
        C[i]--;
        val2pos[C[i]].push_back(i);
    }
    map<pint, vector<lint>> ma;

    IREP(i, N)
    {
        for (auto v : val2pos[i]) rmq.update(v, 1);
        int pos_min = val2pos[i][0], pos_max = val2pos[i].back();
        if (pos_min < pos_max)
        {
            int st = rmq.get(pos_min, pos_max);
            if (st == 0)
            {
                puts("0");
                return 0;
            }
        }

        pint pa(pos_min, pos_max);
        bool nxt_use = false, prv_use = false;
        {
            auto itr1 = ma.lower_bound(pint(pos_max, pos_max));
            if (itr1 != ma.end() and itr1->first.first == pos_max + 1) nxt_use = true;
        }
        {
            auto itr = ma.lower_bound(pint(pos_min, pos_min));
            {
            if (itr != ma.begin() and prev(itr)->first.second == pos_min - 1) prv_use = true;
            }
        }

        pint pa_nxt(pos_min, pos_max);
        vector<lint> tmp{0, 1};

        lint inner_total = 1;
        auto itr = ma.lower_bound(pa);
        while (itr != ma.end() and itr->first.first > pos_min and itr->first.second < pos_max)
        {
            lint t = accumulate(ALL(itr->second), 0LL) % MOD;
            inner_total = inner_total * t % MOD;
            ma.erase(itr);
            itr = ma.lower_bound(pa);
        }

        if (nxt_use)
        {
            auto itr1 = ma.lower_bound(pa);
            pa_nxt.second = itr1->first.second;

            tmp = gen_new_vec(itr1->second);
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
        }
        else if (prv_use)
        {
            auto itr1 = prev(ma.lower_bound(pa));
            pa_nxt.first = itr1->first.first;
            tmp = gen_new_vec(itr1->second);
            ma.erase(itr1);
        }
        REP(i, tmp.size())
        tmp[i] = tmp[i] * inner_total % MOD;
        ma[pa_nxt] = tmp;
    }
    cout << accumulate(ALL(ma.begin()->second), 0LL) % MOD << endl;
}