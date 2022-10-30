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

const int N = 100005;

char str[N];
int a[N], gxx[N], n, ans;

void dfs(int dep, int equal, int sum)
{
    if (dep == -1)
    {
        ans = max(ans, sum);
        return;
    }
    if (!equal)
    {
        ans = max(ans, sum + gxx[dep]);
        return;
    }
    if (str[dep] == '0')
        dfs(dep - 1, 1, sum);
    else
    {
        dfs(dep - 1, 0, sum);
        dfs(dep - 1, 1, sum + a[dep]);
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    gxx[0] = 0;
    if (a[0] > 0) gxx[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        gxx[i] = gxx[i - 1];
        if (a[i] > 0) gxx[i] += a[i];
    }
    scanf("%s", str);
    ans = -lim;
    dfs(n - 1, 1, 0);
    cout << ans << endl;
    return 0;
}