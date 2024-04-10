#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 2 * 100 * 1000;

vi a[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        a[x].pb(i);
    }
    vi res(n, -1);
    int M = maxn;
    int IT = 0;
    while (M > 0)
    {
        while (M > 0 && !sz(a[M])) --M;
        if (M <= 0) break;
        ++IT;
        for (int i = M; i > 0; --i)
        {
            if (!sz(a[i]))
            {
                printf("-1\n");
                return 0;
            }
            res[a[i][sz(a[i]) - 1]] = IT;
            a[i].pop_back();
        }
    }
    cout << IT << "\n";
    for (int i = 0; i < n; ++i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}