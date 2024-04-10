// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e4 + 9, Mod = 1e9 + 7;
int n, q, m, Qcnt = 4269;
inline int Query(int a, int b)
{
    //if (!Qcnt) while (true);
    Qcnt --;
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    //if (r == -1) while (true);
    return (r);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    int Sub = (1 << 11) - 1;
    vector < int > A;
    for (int i = 1; i <= n; i ++)
        A.pb(i);

    int lol[4000];

    mt19937 Rnd(time(0) * (lol[381] + 91134));
    auto Rand = [&](int l, int r){
        int a = Rnd();
        a = abs(a);
        return a % (r - l) + l;
    };

    while (A.size() > 1)
    {
        int k = (int)A.size();
        int rnd = Rand(0, k);
        int rnd2 = rnd;
        while (rnd == rnd2)
            rnd2 = Rand(0, k);
        if (k >= 20 && __builtin_popcount(Query(A[rnd], A[rnd2])) >= (__builtin_popcount(Sub) + 2) / 2)
            continue;
        vector < int > B(k, Sub);
        int Mn = Sub;
        for (int i = 0; i < k; i ++)
            if (i != rnd)
                B[i] = Query(A[i], A[rnd]) & Sub,
                Mn = min(Mn, B[i]);
        set < int > ST;
        for (int i = 0; i < k; i ++)
            if (i != rnd)
                ST.insert(B[i]);
        bool Fail = 0;
        int tt = k - 1;
        for (int i = 1; i < 2048 && tt && !Fail; i ++)
            if ((i | Sub) == Sub)
            {
                if (!ST.count(i))
                    Fail = 1;
                tt --;
            }
        if (!Fail)
            {A = {A[rnd]}; break;}
        vector < int > _A;
        for (int i = 0; i < k; i ++)
            if (i != rnd && B[i] == Mn)
                _A.pb(A[i]);
        A.swap(_A);
        Sub = Mn;
    }

    vector < int > P(n + 1, 0);
    P[A[0]] = 0;
    for (int i = 1; i <= n; i ++)
        if (i != A[0])
            P[i] = Query(i, A[0]);
    printf("!");
    for (int i = 1; i <= n; i ++)
        printf(" %d", P[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}