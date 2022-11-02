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

int main()
{
    string s;
    int res = 0;
    int cur = 0;
    char ts[1000];
    while (1)
    {
        ts[0] = 0;
        gets(ts);
        if (!ts[0]) break;
        string s = ts;
        if (s[0] == '+') cur++;
        else if (s[0] == '-') cur--;
        else
        {
            int cnt = 0;
            while (s[cnt] != ':') cnt++;
            cnt = sz(s) - cnt - 1;
            res += cur * cnt;
        }
    }
    cout << res << "\n";
    return 0;
}