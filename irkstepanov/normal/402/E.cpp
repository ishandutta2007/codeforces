#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

vector <vector <int> > matr;
int n;
int met[2300];

int to(int v)
{
    if (met[v] == 1) return 0;
    met[v] = 1;
    int i, res = 1;
    for (i = 0; i < n; i++)
        if (matr[v][i] == 1)
            res += to(i);
    return res;
}

int from(int v)
{
    if (met[v] == 1) return 0;
    met[v] = 1;
    int i, res = 1;
    for (i = 0; i < n; i++)
        if (matr[i][v] == 1)
            res += from(i);
    return res;
}

int main()
{

    cin >> n;
    int i, j;
    matr.resize(n);

    for (i = 0; i < n; i++)
    {
        matr[i].resize(n);
        for (j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            if (x > 0) matr[i][j] = 1;
            else matr[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
        met[i] = 0;
    int a = to(0);

    for (i = 0; i < n; i++)
        met[i] = 0;
    int b = from(0);

    if (a == n && b == n) cout << "YES";
    else cout << "NO";

}