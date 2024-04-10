#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

const int MAXN = 71;
int tab[MAXN][MAXN];
int n;

int przeciwny(int x)
{
    return (x == 0) ? 1 : 0;
}
bool legal(pii A)
{
    return A.st > 0 && A.nd > 0 && A.nd <= n && A.st <= n;
}
bool visited(pii A)
{
    return tab[A.st][A.nd] != -1;
}
void seet(pii A, int x)
{
    tab[A.st][A.nd] = x;
}
int get(pii A)
{
    return tab[A.st][A.nd];
}

bool identical(pii A, pii B)
{
    if (A.st > B.st || A.nd > B.nd)
        swap(A, B);
    cout << "? " << A.st << " " << A.nd << " " << B.st << " " << B.nd << endl;
    cout.flush();
    int a;
    cin >> a;
    return (a == 1);
}
vector<pii> sasiedzi(pii A)
{
    vector<pii> X;
    for (int l = 0; l <= 2; l++)
    {
        pii B = mp(A.st - l, A.nd - 2 + l);
        pii C = mp(A.st + l, A.nd + 2 - l);
        if (legal(B))
            X.pb(B);
        if (legal(C))
            X.pb(C);
    }
    return X;
}

void bfs(pii A)
{
    queue<pii> Q;
    Q.push(A);
    while (!Q.empty())
    {
        pii X = Q.front();
        Q.pop();
        for (auto Y : sasiedzi(X))
        {
            if (!visited(Y))
            {
                seet(Y, identical(Y, X) ? get(X) : przeciwny(get(X)));
                Q.push(Y);
            }
        }
    }
}

void pre()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            tab[i][j] = -1;
    tab[1][1] = 1;
    tab[n][n] = 0;
}

void zakoncz()
{
    cout << "!" << endl;

    rep(i, n)
    {
        rep(j, n)
        {
            cout << tab[i + 1][j + 1];
        }
        cout << "\n";
    }
    cout.flush();
    exit(0);
}

void solve(int a)
{
    pii A = {a, a};
    pii B = {a + 2, a + 2};
    pii C = {a, a + 1};
    pii D = {a + 1, a + 1};
    pii E = {a + 2, a + 1};

    bool fst = identical(A, E);
    bool ned = identical(C, B);
    if (!fst && !ned)
    {
        if (get(D) == 1)
        {
            seet(E, 0);
            bfs(E);
        }
        else
        {
            seet(C, 1);
            bfs(C);
        }

        zakoncz();
    }
    if (fst)
    {
        seet(E, get(A));
        bfs(E);
        zakoncz();
    }
    if (ned)
    {
        seet(C, get(B));
        bfs(C);
        zakoncz();
    }
}

main()
{
    cin >> n;
    pre();
    bfs({1, 1});
    for (int i = 1;; i = i + 2)
    {
        if (tab[i][i] != tab[i + 2][i + 2])
            solve(i);
    }
}