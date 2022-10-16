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

string S;

int next_zam(int i)
{
    int j = i;
    for (; j < S.size(); j++)
        if (S[j] == '(')
            return j;
    return j;
}

int prev_otw(int i)
{
    int j = i;
    for (; j >= 0; j--)
        if (S[j] == ')')
            return j;
    return j;
}

main()
{
    _upgrade;
    cin >> S;
    vector<int> V;
    int i = 0;
    int j = S.size() - 1;
    while (1)
    {
        i = next_zam(i);
        j = prev_otw(j);
        if (j > i)
        {
            V.push_back(i++);
            V.push_back(j--);
        }
        else
            break;
    }
    sort(all(V));
    if (V.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << V.size() << endl;
        for (int a : V)
            cout << a + 1 << " ";
        cout << endl;
    }
}