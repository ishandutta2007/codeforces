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
    char ts[2000];
    vector<string> v;
    int w = 0;
    while (1)
    {
        if (!gets(ts)) break;
        string s = ts;
        w = max(w, sz(s));
        v.pb(s);
    }
    int last = 0;
    for (int i = 0; i < w + 2; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < sz(v); i++)
    {
        printf("*");
        int x = w - sz(v[i]);
        if (x % 2)
        {
            x /= 2;
            x += last;
            last = 1 - last;
        }
        else
            x /= 2;
        cout << (string(x, ' ') + v[i] + string(w - sz(v[i]) - x, ' ')) << "*\n";
    }
    for (int i = 0; i < w + 2; i++)
        printf("*");
    printf("\n");
    return 0;
}