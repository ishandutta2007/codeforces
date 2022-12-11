#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

ll m[2][2];

int main()
{

    string s;
    cin >> s;

    int g[100500], group = 1;

    for (int i = 0; i < s.size(); i++)
    {
        if (!i) g[i] = group;
        else
        {
            if (s[i] != s[i - 1]) g[i] = ++group;
            else g[i] = group;
        }
        ++m[g[i] % 2][i % 2];
    }

    ll chet = 0, nech = 0;
    for (int i = 0; i < s.size(); i++)
    {
        --m[g[i] % 2][i % 2];
        ++nech;
        if (i % 2)
        {
            chet += m[g[i] % 2][0];
            nech += m[g[i] % 2][1];
        }
        else
        {
            chet += m[g[i] % 2][1];
            nech += m[g[i] % 2][0];
        }
    }

    cout << chet << " " << nech;

}