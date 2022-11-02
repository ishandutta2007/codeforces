#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <sstream>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

int main()
{
    char buf[100000];
    gets(buf);
    for (int i = 0; buf[i]; ++i)
        if (buf[i] == ',') buf[i] = ' ';
    stringstream ss(buf);
    int n = 0;
    vi v;
    int x;
    while (ss >> x)
    {
        n++;
        v.pb(x);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int cur = v[0];
    bool f = true;
    for (int i = 1; i < sz(v); ++i)
    {
        if (v[i] != v[i - 1] + 1)
        {
            if (!f)
                printf(",");
            else
                f = false;
            if (v[i - 1] == cur)
                printf("%d", cur);
            else
                printf("%d-%d", cur, v[i - 1]);
            cur = v[i];
        }
        else
        {
            // do nothing
        }
    }
    if (!f)
        printf(",");
    else
        f = false;
    if (v[sz(v) - 1] == cur)
        printf("%d", cur);
    else
        printf("%d-%d", cur, v[sz(v) - 1]);
    printf("\n");
    return 0;
}