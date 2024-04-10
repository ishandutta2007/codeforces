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

char s[N];
int L[N], R[N], cover[N], n;

int fix(int i)
{
    if (i == n) i = 0;
    if (i == -1) i = n - 1;
    return i;
}

int main(){
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        if (s[i] == '0') R[i] = true;
        else L[fix(i + 1)] = true;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!L[i] || !R[i]) continue;
        if (L[fix(i - 1)])
        {
            ++ans;
            for (int j = i; ; j = fix(j - 1))
            {
                cover[j] = true;
                if (!L[j]) break;
            }
        }
        if (R[fix(i + 1)])
        {
            ++ans;
            for (int j = i; ; j = fix(j + 1))
            {
                cover[j] = true;
                if (!R[j]) break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (cover[i]) continue;
        cover[i] = true;
        int l = i;
        int r = i;
        int cur = 1;
        while (!cover[fix(l - 1)]) l = fix(l - 1), cover[l] = true, ++cur;
        while (!cover[fix(r + 1)]) r = fix(r + 1), cover[r] = true, ++cur;
        ans += (cur + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}