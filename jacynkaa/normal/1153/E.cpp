#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>

vector<int> X[2];
int n;

int zapytaj(pii A, pii B)
{
    int a;
    cout << "? " << A.st << " " << A.nd << " " << B.st << " " << B.nd << endl;
    cin >> a;
    return a;
}
void znajdz(int co) //0 szukam wspolrzednej iksowej, 1 szukam igrekowej
{
    int sum = 0;
    int a;

    for (int i = 1; i <= n; i++)
    {
        pii Q = mp(i, n);
        if (co == 1)
            swap(Q.st, Q.nd);

        a = zapytaj(mp(1, 1), Q);

        if ((a & 1) != (sum & 1))
        {
            X[co].push_back(i);
            sum = a;
        }
    }
}

void odpowiedz(pii A, pii B)
{
    cout << "! " << A.st << " " << A.nd << " " << B.st << " " << B.nd << endl;
    exit(0);
}
void oba_znalezione()
{
    if ((zapytaj(mp(1, 1), mp(X[0][0], X[1][0])) & 1) == 0)
        swap(X[0][0], X[0][1]);
    odpowiedz(mp(X[0][0], X[1][0]), mp(X[0][1], X[1][1]));
}

void znajdz_ponownie(int co, int d)
{
    int p = 1;
    int q = n;
    while (p != q)
    {
        int s = (p + q) / 2;
        pii Q = mp(s, d);
        if (co == 1)
            swap(Q.st, Q.nd);

        if (zapytaj(mp(1, 1), Q) % 2 == 0)
            p = s + 1;
        else
            q = s;
    }
    X[co].push_back(p);
    X[co].push_back(p);
    oba_znalezione();
}

int main()
{
    cin >> n;
    znajdz(0);
    znajdz(1);
    /*
    cerr << "first:" << endl;
    for (int i = 0; i < (int)X[0].size(); i++)
        cerr
            << X[0][i] << " ";
    cerr << endl;

    cerr << "second:" << endl;
    for (int i = 0; i < (int)X[1].size(); i++)
        cerr << X[1][i] << " ";
    cerr << endl;
    // return 0;
    */

    if (X[0].size() != 0 && X[1].size() != 0)
        oba_znalezione();
    if (X[0].size() == 0)
        znajdz_ponownie(0, X[1][0]);
    znajdz_ponownie(1, X[0][0]);
    return 0;
}