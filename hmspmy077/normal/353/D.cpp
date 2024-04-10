#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template<class T> T abs(T x){return x < 0 ? -x : x;}

const int N = 1000005;

int f[N];
char s[N];
vector<int> a;

int main(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        if (s[i] == 'F')
            a.pb(i);
    for (int i = sz(a) - 1; i > 0; --i)
        a[i] = a[i] - a[i - 1] - 1;
    int cur = 0, ans = 0;
    for (int i = sz(a) - 1; i >= 0; --i)
    {
        if (i + 1 == sz(a))
        {
            cur = a[i];
            ans = max(cur, ans);
            continue;
        }
        cur = max(0, cur - 1);
        if (a[i])
        {
            cur = cur + a[i];
            ans = max(ans, cur + sz(a) - i - 1);
        }
    }
    cout << ans << endl;
    return 0;
}