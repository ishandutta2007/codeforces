#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ld eps = 0.0000001;

ld dist (ld a, ld b, ld c, ld d)
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

bool eq (ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool ge (ld a, ld b)
{
    return a - b >= eps;
}

int main()
{

    int n, m;
    cin >> n >> m;

    if (n * m)
    {
        ld d1 = sqrt((n - 1) * (n - 1) * 1.0 + m * m * 1.0) + sqrt(n * n * 1.0 + m * m * 1.0) + sqrt(n * n * 1.0 + (m - 1) * (m - 1) * 1.0);
        ld d2 = 2 * sqrt(n * n * 1.0 + m * m * 1.0) + max(n, m);
        ld d3 = 2 * sqrt(n * n * 1.0 + (m - 1) * (m - 1) * 1.0) + sqrt(n * n * 1.0 + m * m * 1.0);
        ld d4 = 2 * sqrt((n - 1) * (n - 1) * 1.0 + m * m * 1.0) + sqrt(n * n * 1.0 + m * m * 1.0);
        ld maxim = 0;
        if (ge(d1, maxim)) maxim = d1;
        if (ge(d2, maxim)) maxim = d2;
        if (ge(d3, maxim)) maxim = d3;
        if (ge(d4, maxim)) maxim = d4;
        if (eq(maxim, d1))
        {
            cout << "0 1\n";
            cout << n << " " << m << "\n";
            cout << "0 0\n";
            cout << n - 1 << " " << m << "\n";
        }
        else if (eq(maxim, d2))
        {
            cout << "0 0\n";
            cout << n << " " << m << "\n";
            if (m > n) cout << n << " 0\n" << "0 " << m << "\n";
            else cout << "0 " << m << "\n" << n << " 0\n";
        }
        else if (eq(maxim, d3))
        {
            cout << "0 1\n";
            cout << n << " " << m << "\n";
            cout << "0 0\n";
            cout << n << " " << m - 1 << "\n";
        }
        else
        {
            cout << "1 0\n";
            cout << n << " " << m << "\n";
            cout << "0 0\n";
            cout << n - 1 << " " << m << "\n";
        }
    }

    if (!n)
    {
        cout << "0 1\n";
        cout << "0 " << m << "\n";
        cout << "0 0\n";
        cout << "0 " << m - 1 << "\n";
    }

    if (!m)
    {
        cout << "1 0\n";
        cout << n << " 0\n";
        cout << "0 0\n";
        cout << n - 1 << " 0\n";
    }

}