#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <bitset>
#include <cmath>

#define pb push_back

using namespace std;

int a[120], b[120];

void f (int n, int a[120])
{
    if (n == 1) a[0] = 1;
    else if (n == 2) {a[0] = 3; a[1] = 4;}
    else if (n % 2)
    {
        a[0] = 2;
        for (int i = 1; i < n - 1; i++)
            a[i] = 1;
        a[n - 1] = (n + 1) / 2;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
            a[i] = 1;
        a[n - 1] = (n - 2) / 2;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    f(n, a);
    f(m, b);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i] * b[j] << " ";
        cout << "\n";
    }

}