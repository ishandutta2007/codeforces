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

int d[2000000];

ii st[2000000];
int ss = 0;

int main()
{
    string s;
    cin >> s;
    int l = 0, cnt = 1;
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= sz(s); i++)
    {
        char cur = s[i - 1];
        d[i] = 0;
        if (cur == '(')
        {
            st[ss++] = ii(0, i);
            continue;
        }
        if (ss == 0 || st[ss - 1].first == 1)
        {
            st[ss++] = ii(1, i);
            continue;
        }
        int beg = st[ss - 1].second;
        ss--;
        int cl = d[beg - 1] + (i - beg + 1);
        d[i] = cl;
        if (cl > l)
            l = cl, cnt = 1;
        else if (cl == l) cnt++;
    }
    printf("%d %d\n", l, cnt);
    return 0;
}