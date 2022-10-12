#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i != (n); i++)
#define fi first
#define se second
#define pb push_back
#define sz size()

int n;
int d[50000];

int main()
{
    int q;
    cin >> q;
    forn(i, q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c)
        {
            cout << b << " " << c << endl;
        }
        else
        {
            cout << a << " " << d << endl;
        }
    }
}