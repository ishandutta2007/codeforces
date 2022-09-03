#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


vector<vector<int>> permutations;
map<vector<int>, int> perm2id;

int N, K;
lint ret;
int fac;

vector<vector<int>> trans;

vector<int> P;

void calcbs(bitset<120> &bs)
{
    bs[0] = 1;
    while (true)
    {
        bool flg = true;
        REP(i, fac) if (bs[i]) REP(j, fac) if (bs[j])
        {
            if (!bs[trans[i][j]]) bs[trans[i][j]] = 1, flg = false;
            if (!bs[trans[j][i]]) bs[trans[j][i]] = 1, flg = false;
        }
        if (flg) return;
    }
}

vector<bitset<120>> Blocks;
constexpr int B = 1000;

vector<bitset<120>> subgroups;
unordered_map<bitset<120>, int> subgrp_id;
vector<int> sz_subgroup;

int append_subgrp(bitset<120> b)
{
    if (!subgrp_id.count(b))
    {
        subgrp_id[b] = subgroups.size();
        subgroups.push_back(b);
    }
    return subgrp_id[b];
}

vector<vector<int>> subgrp_add;


void divide_and_conquer(int L, int R)
{
    if (L >= R) return;
    if (L + 1 == R)
    {
        ret += sz_subgroup[subgrp_add[0][P[L]]];
        return;
    }
    int C = (L + R) / 2;
    map<int, int> ml, mr;
    int g = 0;
    FOR(x, C, R)
    {
        g = subgrp_add[g][P[x]];
        mr[g]++;
    }
    g = 0;
    IFOR(x, L, C)
    {
        g = subgrp_add[g][P[x]];
        ml[g]++;
    }
    for (auto pl : ml) for (auto pr : mr)
    {
        int g = pl.first;
        REP(d, fac) if (subgroups[pr.first][d]) g = subgrp_add[g][d];
        ret += (lint)sz_subgroup[g] * pl.second * pr.second;
    }
    divide_and_conquer(L, C);
    divide_and_conquer(C, R);
}

int main()
{
    cin >> N >> K;
    Blocks.resize((N + (B - 1)) / B);

    fac = 1;
    REP(i, K) fac *= (i + 1);

    vector<int> st(K);
    iota(ALL(st), 0);
    do {
        int id_ = perm2id.size();
        permutations.push_back(st);
        perm2id[st] = id_;
    } while (next_permutation(ALL(st)));

    P.resize(N);
    REP(i, N)
    {
        vector<int> s(K);
        cin >> s;
        REP(i, K) s[i]--;
        P[i] = perm2id.at(s);
    }

    trans.resize(fac, vector<int>(fac));
    REP(i, fac) REP(j, fac)
    {
        vector<int> ji(K);
        REP(k, K) ji[k] = permutations[i][permutations[j][k]];
        trans[i][j] = perm2id.at(ji);
    }

    bitset<120> bs_sub;
    bs_sub[0] = 1;
    append_subgrp(bs_sub);
    REP(i, fac) bs_sub[i] = 1;
    append_subgrp(bs_sub);

    while (subgroups.size() > subgrp_add.size())
    {
        int i = subgrp_add.size();
        vector<int> vadd(fac, -1);
        REP(d, fac)
        {
            bs_sub = subgroups[i];
            bs_sub[d] = 1;
            calcbs(bs_sub);
            vadd[d] = append_subgrp(bs_sub);
        }
        subgrp_add.emplace_back(vadd);
    }
    for (auto s : subgroups) sz_subgroup.push_back(s.count());

    ret = 0;
    divide_and_conquer(0, N);

    cout << ret << endl;
}