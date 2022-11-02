#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
//#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

bool a[8][8];

int main()
{
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
            a[i][j] = s[j] == 'B';
    }
    int res = 1000;
    for (int m1 = 0; m1 < (1 << 8); m1++)
        for (int m2 = 0; m2 < (1 << 8); m2++)
        {
            bool ok = true;
            int cur = 0;
            for (int i = 0; i < 8; i++)
            {
                if ((m1 >> i) & 1) cur++;
                if ((m2 >> i) & 1) cur++;
            }
            if (cur >= res) continue;
            for (int i = 0; i < 8 && ok; i++)
                for (int j = 0; j < 8; j++)
                    if (a[i][j] != (((m1 >> i) & 1) || ((m2 >> j) & 1)))
                    {
                        ok = false;
                        break;
                    }
            if (ok)
                res = min(res, cur);
        }
    cout << res << "\n";
    return 0;
}