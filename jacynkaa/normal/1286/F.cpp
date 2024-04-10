#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
const int MAXN = 21;

long long sum[1 << MAXN];
int best[1 << MAXN];
int cnt[1 << MAXN];
long long tab[MAXN];
int pot2[MAXN];
int n;

void pre()
{
    rep(i, MAXN)
        pot2[i] = (1 << i);

    for (int S = 0; S < pot2[n]; S++)
    {
        cnt[S] = __builtin_popcount(S);
        rep(i, MAXN) if (S & pot2[i])
        {
            sum[S] += tab[i];
            best[S] = (tab[i] == 0) ? 0 : 1;
            //cnt[S]++;
        }
    }
}

void count()
{

    for (int S = 0; S < pot2[n]; S++)
    {
        if (cnt[S] < 2)
            continue;

        best[S] = cnt[S];

        int ile = cnt[S];
        int ilep2 = ile / 2;
        bool znalazlem = ((sum[S] + cnt[S] - 1) % 2 != 0);

        for (int Sp = (S - 1) & S; Sp; Sp = (Sp - 1) & S)
        {
            if (best[Sp] + best[S ^ Sp] < best[S])
            {
                znalazlem = true;
                best[S] = best[Sp] + best[S ^ Sp];
            }

            if (!znalazlem) // && cnt[Sp] == ilep2)
            {
                if (sum[Sp] - sum[S ^ Sp] < ile && sum[Sp] - sum[S ^ Sp] > -ile)
                {
                    znalazlem = true;
                    best[S] = cnt[S] - 1;
                }
            }
        }
        //cerr << S << " " << best[S] << endl;
    }
    cout << best[pot2[n] - 1] << endl;
}

main()
{
    _upgrade;
    cin >> n;
    rep(i, n) cin >> tab[i];
    pre();
    count();
}