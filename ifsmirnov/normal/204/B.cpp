#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long i64;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

map<int, int> f, b;
set<int> a;
int n;
void scan()
{
    cin >> n;
    forn(i, n)
    {
        int x, y;
        cin >> x >> y;
        ++f[x];
        if (y != x)
            ++b[y];
        a.insert(x);
        a.insert(y);
    }
    n = (n+1)/2;
}

int main()
{
    scan();
    int mx = 10000000;
    for (set<int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        int x = *it;
        int ff = f[x], bb = b[x];
        if (ff >= n)
            mx = 0;
        else if (ff+bb >= n)
            mx = min(mx, n-ff);
    }
    cout << (mx == 10000000 ? -1 : mx) << endl;
    
    return 0;
}