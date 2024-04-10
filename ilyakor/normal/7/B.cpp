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

int mem[200];
int mt[200];

int main()
{
    memset(mem, 0, sizeof(mem));
    int t, m;
    cin >> t >> m;
    int cnt = 1;
    for (int it = 0; it < t; it++)
    {
        string s;
        cin >> s;
        if (s == "alloc")
        {
            int n;
            cin >> n;
            int ind = -1;
            for (int i = 0; i + n <= m; i++)
            {
                bool ok = true;
                for (int j = 0; j < n; j++)
                    if (mem[i + j])
                    {
                        ok = false;
                        break;
                    }
                if (ok)
                {
                    ind = i;
                    break;
                }
            }
            if (ind == -1)
            {
                cout << "NULL\n";
                continue;
            }
            for (int i = 0; i < n; i++)
                mem[ind + i] = cnt;
            cout << cnt << "\n";
            cnt++;
        }
        else if (s == "erase")
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                continue;
            }
            int tot = 0;
            for (int i = 0; i < m; i++)
                if (mem[i] == x)
                    tot++, mem[i] = 0;
            if (!tot)
                printf("ILLEGAL_ERASE_ARGUMENT\n");
        }
        else
        {
            memset(mt, 0, sizeof(mt));
            int w = 0;
            for (int i = 0; i < m; i++)
                if (mem[i])
                    mt[w++] = mem[i];
            memcpy(mem, mt, sizeof(mt));
        }
    }
    return 0;
}