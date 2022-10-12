#include<iostream>
#include<algorithm>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define int int16_t
int n, p[8505];
int wh[8505];
int ans[8505];
int level[8505];
int nxt[9][8505];
int prv[9][8505];
pair<int, int> bros[9][8505];
int svd, lsz, l;

inline void go(int &f)
{
    int id = f, t = 0; //++
    f = nxt[l][f];
    if (wh[f] < wh[id]) id = f, t = 1; //-+
    f = nxt[l][f];
    if (wh[f] < wh[id]) id = f, t = 2; //--
    f = nxt[l][f];
    if (t == 2) bros[l - 1][id] = {prv[l][prv[l][id]], prv[l][id]};
    if (t == 1) bros[l - 1][id] = {prv[l][id], nxt[l][id]};
    if (t == 0) bros[l - 1][id] = {nxt[l][id], nxt[l][nxt[l][id]]};
    level[id]--, lsz++, nxt[l - 1][svd] = id, nxt[l - 1][id] = n + 1, prv[l - 1][id] = svd;
    svd = id;
}

bool comp(int a, int b)
{
    return wh[a] < wh[b];
}

struct genQ{
    int lvl, pl, pr;
};
genQ s10[10000];
int s10size;

int pos[4];
int possize;

inline void solve2(int &l)
{
    if (possize < 4)
    {
        for (int i = 0; i < possize; i++)
        {
            if (ans[pos[i]] == 0)
            {
                for (int j = l; j <= l + 2; j++)
                {
                    int t = 1;
                    for (int k = 0; k < possize; k++) if (ans[pos[k]] == j) t = 0;
                    if (t) {ans[pos[i]] = j; break;}
                }
            }
        }
        return;
    }
    int lst = 0;
    for (int i = 1; i < 4; i++) if (wh[pos[i]] > wh[pos[lst]]) lst = i;
    if (ans[pos[lst]] == 0)
    {
        if (ans[pos[3 - lst]] == 0)
        {
            if (lst == 0) ans[pos[0]] = l + 2, ans[pos[1]] = l, ans[pos[2]] = l + 1, ans[pos[3]] = l + 2;
            if (lst == 1) ans[pos[0]] = l, ans[pos[1]] = l + 2, ans[pos[2]] = l + 1, ans[pos[3]] = l + 2;
            if (lst == 2) ans[pos[0]] = l, ans[pos[1]] = l + 1, ans[pos[2]] = l, ans[pos[3]] = l + 2;
            if (lst == 3) ans[pos[0]] = l, ans[pos[1]] = l + 1, ans[pos[2]] = l + 2, ans[pos[3]] = l;
        }
        else
        {
            if (lst > 1)
            {
                lst = 3 - lst;
                reverse(pos, pos + 4);
            }
            if (lst == 0)
            {
                ans[pos[1]] = 3 * l + 3 - ans[pos[2]] - ans[pos[3]];
                ans[pos[0]] = ans[pos[1]] + 1; if (ans[pos[0]] == l + 3) ans[pos[0]] -= 3;
            }
            if (lst == 1)
            {
                ans[pos[1]] = ans[pos[3]];
                ans[pos[0]] = 3 * l + 3 - ans[pos[1]] - ans[pos[2]];
            }
        }
        return;
    }
    if (lst > 1)
    {
        lst = 3 - lst;
        reverse(pos, pos + 4);
    }
    if (lst == 1)
    {
        if (wh[pos[2]] < wh[pos[3]] || wh[pos[2]] < wh[pos[0]])
        {
            ans[pos[3]] = ans[pos[0]];
            ans[pos[2]] = 3 * l + 3 - ans[pos[0]] - ans[pos[1]];
        }
        else
        {
            ans[pos[3]] = ans[pos[1]];
            ans[pos[2]] = 3 * l + 3 - ans[pos[0]] - ans[pos[1]];
        }
    }
    else
    {
        ans[pos[2]] = ans[pos[1]] + 1;
        if (ans[pos[2]] == l + 3) ans[pos[2]] -= 3;
        ans[pos[3]] = ans[pos[2]] + 1;
        if (ans[pos[3]] == l + 3) ans[pos[3]] -= 3;
    }
}

inline void solve1()
{
    int pl = s10[s10size].pl;
    int pr = s10[s10size].pr;
    int lvl = s10[s10size].lvl;
    s10size--;
    possize = 0;
    if (pl != 0){
        if (bros[lvl][pl].first > pl) pos[possize++] = (bros[lvl][pl].first);
        if (bros[lvl][pl].second > pl) pos[possize++] = (bros[lvl][pl].second);
    }
    if (pr != n + 1) {
        if (bros[lvl][pr].first < pr) pos[possize++] = (bros[lvl][pr].first);
        if (bros[lvl][pr].second < pr) pos[possize++] = (bros[lvl][pr].second);
    }
    int l = 3 * lvl + 1;
    int t = 0;
    for (int i = 0; i < possize; i++)
    {
        if (ans[pos[i]] == 0) t = 1;
    }
    if (!t) return;
    solve2(l);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) wh[p[i]] = i, ans[i] = 0, nxt[8][i] = i + 1, level[i] = 8, prv[8][i] = i - 1;
    for (int i = 1; i <= 8; i++) nxt[i][0] = 1, nxt[i][n + 1] = n + 1;
    wh[n + 1] = n + 1;
    if (n > 4)
    for (l = 8; l >= 1; l--)
    {
        int f = nxt[l][0];
        lsz = 0, svd = 0;
        while (f != n + 1)
            go(f);
        if (lsz <= 4) break;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int gl = level[p[i]]; gl < 8; gl++)
        {
            int LL = prv[gl][p[i]], RR = nxt[gl][p[i]];
            s10[++s10size] = {gl, LL, RR};
            s10[++s10size] = {gl, LL, p[i]};
            s10[++s10size] = {gl, p[i], RR};
            prv[gl][RR] = LL;
            nxt[gl][LL] = RR;
        }
    }
    while (s10size > -1) solve1();
    for (int lvl = 1; lvl <= 8; lvl++)
    {
        possize = 0;
        for (int i = 1; i <= n; i++) if (lvl == level[i] && ans[i] == 0) pos[possize++] = i;
        int c = lvl * 3 - 2;
        solve2(c);
    }
    for (int i = 1; i <= n; i++) printf("%d ", 25 - ans[i]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}