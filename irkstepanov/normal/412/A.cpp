#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
ll mod = 1000000007;
ll inf = 1000000000;

struct pt
{
    double x, y;
};

double dist (pt a, pt b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool smaller (double a, double b)
{
    return (b - a >= 0.000001);
}

set <int> p;

void f (int n, map <int, int> &mapn)
{
    for (int d = 2; d * d <= n; d++)
    {
        if (n % d == 0) p.insert(d);
        while (n % d == 0)
        {
            n /= d;
            ++mapn[d];
        }
    }
    if (n > 1)
    {
        ++mapn[n];
        p.insert(n);
    }
}

int main()
{

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    --k;
    vector <string> toleft, toright;

    for (int i = k; i < s.size(); i++)
    {
        string tmp = "PRINT ";
        tmp += s[i];
        tmp += "\n";
        toright.pb(tmp);
        if (i != (int) s.size() - 1) toright.pb("RIGHT\n");
    }

    if (k)
    {
        for (int i = (int) s.size() - 1; i >= k; i--)
            toright.pb("LEFT\n");
        for (int i = k - 1; i >= 0; i--)
        {
            string tmp = "PRINT ";
            tmp += s[i];
            tmp += "\n";
            toright.pb(tmp);
            if (i) toright.pb("LEFT\n");
        }
    }

    for (int i = k; i >= 0; i--)
    {
        string tmp = "PRINT ";
        tmp += s[i];
        tmp += "\n";
        toleft.pb(tmp);
        if (i) toleft.pb("LEFT\n");
    }

    if (k != (int) s.size() - 1)
    {
        for (int i = 0; i <= k; i++)
            toleft.pb("RIGHT\n");
        for (int i = k + 1; i < s.size(); i++)
        {
            string tmp = "PRINT ";
            tmp += s[i];
            tmp += "\n";
            toleft.pb(tmp);
            if (i != (int) s.size() - 1) toleft.pb("RIGHT\n");
        }
    }

    vector <string> ans;
    if (toleft.size() < toright.size()) ans = toleft;
    else ans = toright;

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

}