// Screw this ..
#include<bits/stdc++.h>
#define lc (id << 1)
#define rc (lc ^ 1)
#define md (l + r >> 1)
using namespace std;
const int N = 8e5 + 9, MXS = N * 4;
int n, q, k;
int MN[MXS], F[MXS], LZ[MXS];
set < int > ST, DL;
set < pair < int , int > > G;
inline void Shift(int id)
{
    MN[lc] += LZ[id];
    MN[rc] += LZ[id];
    LZ[lc] += LZ[id];
    LZ[rc] += LZ[id];
    LZ[id] = 0;
}
void Add(int le, int ri, int val, int id = 1, int l = 1, int r = N)
{
    if (ri <= l || r <= le)
        return ;
    if (le <= l && r <= ri)
    {
        MN[id] += val;
        LZ[id] += val;
        return ;
    }
    Shift(id);
    Add(le, ri, val, lc, l, md);
    Add(le, ri, val, rc, md, r);
    MN[id] = min(MN[lc], MN[rc]);
    if (MN[id] == MN[lc])
        F[id] = F[lc];
    else
        F[id] = F[rc];
}
void Build(int id = 1, int l = 1, int r = N)
{
    F[id] = l;
    if (r - l > 1)
        Build(lc, l, md), Build(rc, md, r);
}
pair < int , int > GetMin(int le, int ri, int id = 1, int l = 1, int r = N)
{
    if (ri <= l || r <= le || MN[id] > 1)
        return make_pair((int)1e9, -1);
    if (le <= l && r <= ri)
        return make_pair(MN[id], F[id]);
    Shift(id);
    auto X = GetMin(le, ri, lc, l, md);
    if (X.first == 1)
        return (X);
    return GetMin(le, ri, rc, md, r);
}
int main()
{
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i < N; i ++)
        ST.insert(i);
    Build();
    for (; q; q --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (!G.count({a, b}))
        {
            G.insert({a, b});
            int r = b + abs(a - k);
            auto it = ST.lower_bound(r);
            if (it == ST.end()) exit(0);
            Add(r, (* it) + 1, 1);
            DL.insert(* it);
            ST.erase(it);
        }
        else
        {
            G.erase({a, b});
            int r = b + abs(a - k);
            auto it = ST.lower_bound(r);
            int id = GetMin(r, * it).second;
            ST.insert(id);
            DL.erase(id);
            Add(r, id + 1, -1);
        }
        if (!DL.size())
            printf("0\n");
        else
            printf("%d\n", max(*DL.rbegin() - n, 0));
    }
    return 0;
}