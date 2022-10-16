#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;

#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)

int curr_max = -1;

int ask(int x, vector<int> X)
{
    cout << 1 << " " << X.size() << " " << x << " ";
    for (int i = 0; i < X.size() - 1; i++)
        cout << X[i] << " ";
    cout << X[X.size() - 1] << endl;
    int a;
    cin >> a;
    return a;
}

int wierzcholek(vector<int> A)
{
    if (A.size() == 1)
        return A[0];
    else
    {
        int s = A.size();
        vector<int> B;
        vector<int> C;
        for (int i = 0; i < A.size(); i++)
        {
            if (i < A.size() / 2)
                B.push_back(A[i]);
            else
            {
                C.push_back(A[i]);
            }
        }
        int x = ask(1, B);
        if (x == curr_max)
            return wierzcholek(B);

        return wierzcholek(C);
    }
}

main()
{
    int Z;
    cin >> Z;
    while (Z--)
    {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 2; i <= n; i++)
            A.push_back(i);
        curr_max = ask(1, A);
        int x = wierzcholek(A);
        vector<int> Q;
        for (int i = 1; i <= n; i++)
            if (i != x)
                Q.push_back(i);
        int a = ask(x, Q);
        cout << -1 << " " << a << endl;
    }
}