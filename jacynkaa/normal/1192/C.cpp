#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl '\n'
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int32_t i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define int long long

const int MOD = 998244353;
const int slownik = 'Z' - 'A' + 1 + 'z' - 'a' + 1 + '9' - '0' + 1;
const int dlugosc = 11;
int ans = 0;

int matrix[dlugosc][slownik][slownik];
int kombinacje[dlugosc][slownik][slownik][slownik];
unordered_set<string> S;

inline int getNum(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 26;
    return c - '0' + 52;
}

inline int mult(int a, int b)
{
    return (a * b) % MOD;
}

void add(string s)
{
    if (S.find(s) == S.end())
    {
        matrix[s.size()][getNum(s[0])][getNum(s.back())]++;
        S.insert(s);
    }
}

void wczytywanie()
{
    int n;
    cin >> n;
    rep(i, n)
    {
        string s;
        cin >> s;
        add(s);
        reverse(all(s));
        add(s);
    }
}

void akcja()
{

    rep(i, slownik) for (int32_t j = i; j < slownik; j++)
        rep(k, slownik)
            rep(l, slownik) for (int32_t dl = 3; dl < dlugosc; dl++)
                kombinacje[dl][i][j][k] += matrix[dl][l][i] * matrix[dl][l][j] * matrix[dl][l][k];

    rep(i, slownik)
        rep(j, slownik)
            rep(k, slownik) for (int32_t dl = 3; dl < dlugosc; dl++)
                kombinacje[dl][i][j][k] %= MOD;

    for (int32_t i = 0; i < slownik; i++)
        for (int32_t j = i; j < slownik; j++)
            for (int32_t k = j; k < slownik; k++)
                rep(l, slownik) for (int32_t dl = 3; dl < dlugosc; dl++)
                {
                    if (i != j && j != k)
                    {
                        ans = (ans + 6 * mult(kombinacje[dl][i][j][k], kombinacje[dl][i][j][l]) * mult(kombinacje[dl][j][k][l], kombinacje[dl][i][k][l])) % MOD;
                        continue;
                    }
                    if (i == k)
                    {
                        ans = (ans + mult(kombinacje[dl][i][j][k], kombinacje[dl][i][j][l]) * mult(kombinacje[dl][j][k][l], kombinacje[dl][i][k][l])) % MOD;
                        continue;
                    }
                    if (i == j)
                    {
                        ans = (ans + 3 * mult(kombinacje[dl][i][j][k], kombinacje[dl][i][j][l]) * mult(kombinacje[dl][j][k][l], kombinacje[dl][i][k][l])) % MOD;
                        continue;
                    }
                    if (k == j)
                    {
                        ans = (ans + 3 * mult(kombinacje[dl][i][j][k], kombinacje[dl][i][j][l]) * mult(kombinacje[dl][j][k][l], kombinacje[dl][i][k][l])) % MOD;
                        continue;
                    }
                }
}

main()
{

    _upgrade;
    wczytywanie();
    akcja();
    cout << ans << endl;
}