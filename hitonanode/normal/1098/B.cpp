#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int checkH(vector<char> v, vector<string> &S)
{
    int bad = 0;
    REP(h, S.size())
    {
        int tmp1 = 0, tmp2 = 0;
        REP(w, S[h].size())
        {
            if (S[h][w] != v[h % 2 * 2 + w % 2]) tmp1++;
            if (S[h][w] != v[h % 2 * 2 + (w + 1) % 2]) tmp2++;
        }
        bad += min(tmp1, tmp2);
    }
    return bad;
}

vector<string> build(vector<char> w, int H, int W, vector<string> &S)
{
    vector<string> ret(H);
    REP(i, H)
    {
        char c0 = w[i % 2 * 2 + 0];
        char c1 = w[i % 2 * 2 + 1];
        string s0, s1;
        REP(j, W)
        {
            s0 += (j % 2 ? c0 : c1);
            s1 += (j % 2 ? c1 : c0);
        }
        int b0 = 0, b1 = 0;
        REP(j, W)
        {
            if (s0[j] != S[i][j]) b0++;
            if (s1[j] != S[i][j]) b1++;
        }
        ret[i] = (b0 < b1 ? s0 : s1);
    }
    return ret;
}

int main()
{
    int N, M;
    vector<string> S, Strans;

    cin >> N >> M;
    S.resize(N);
    cin >> S;
    vector<char> w1{'A', 'C', 'G', 'T'};
    vector<pair<int, vector<char>>> hret, wret;
    do {
        hret.emplace_back(checkH(w1, S), w1);
    } while (next_permutation(ALL(w1)));
    Strans.resize(M);
    REP(i, N) REP(j, M) Strans[j] += S[i][j];
    w1 = {'A', 'C', 'G', 'T'};
    do
    {
        wret.emplace_back(checkH(w1, Strans), w1);
    } while (next_permutation(ALL(w1)));
    sort(ALL(hret));
    sort(ALL(wret));

    vector<string> ret;
    if (hret[0].first < wret[0].first)
    {
        ret = build(hret[0].second, N, M, S);
    }
    else
    {
        vector<string> rettrans = build(wret[0].second, M, N, Strans);
        ret.resize(N);
        REP(i, N) REP(j, M) ret[i] += rettrans[j][i];
    }
    REP(i, N)
    {
        printf("%s\n", ret[i].c_str());
    }
}