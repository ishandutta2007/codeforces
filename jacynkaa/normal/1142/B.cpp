#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
//#pragma GCC optimize("-O3")
//#define endl tutaj n
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)

const int sqrtt = 400;
const int inf = 12345678;
const int stala = 5000000;
set<int> gdzie_sa[stala];
int nastepnik[stala];
int nastepniksqrt[stala];
int MIN[stala];
int permutacja[stala];
int ktory[stala];
int M[stala];
int n, m, q;

int nastepny(int x)
{
    return (ktory[x] == n - 1) ? permutacja[0] : permutacja[(ktory[x] + 1)];
}
int poprzedni(int x)
{
    return (ktory[x] == 0) ? permutacja[n - 1] : permutacja[(ktory[x] - 1)];
}

void wczytywanie() //uwaga n 0
{
    cin >> n >> m >> q;
    REP(i, n)
    {
        cin >> permutacja[i];
        ktory[permutacja[i]] = i;
    }
    REP(i, m)
    {
        cin >> M[i];
        gdzie_sa[M[i]].insert(i);
    }

    for (int i = m - 1; i >= 0; i--)
    {
        int k = nastepny(M[i]);
        auto c = gdzie_sa[k].lower_bound(i);
        if (c == gdzie_sa[k].end())
            nastepnik[i] = inf;
        else
            nastepnik[i] = *c;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        int x = i;
        REP(j, sqrtt)
        {
            if (x == inf)
                break;
            x = nastepnik[x];
        }
        nastepniksqrt[i] = x;
    }
    MIN[m] = 1234567;
    int l = (n - 1) % sqrtt;
    int k = (n - 1) / sqrtt;
    for (int i = m - 1; i >= 0; i--)
    {
        int x = i;
        REP(j, k)
        {
            if (x == inf)
                break;
            x = nastepniksqrt[x];
        }
        REP(j, l)
        {
            if (x == inf)
                break;
            x = nastepnik[x];
        }

        MIN[i] = min(MIN[i + 1], x);
    }
    // REP(i, m)
    // cerr << i << " " << nastepnik[i] << " " << nastepniksqrt[i] << " " << MIN[i] << endl;
    REP(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (MIN[l] <= r)
            cout << 1;
        else
        {
            cout << 0;
        }
    }
    cout << endl;
}

main()
{
    _upgrade;
    wczytywanie();
}