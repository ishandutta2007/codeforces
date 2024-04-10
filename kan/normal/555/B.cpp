#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

struct tsob
{
    ll x, end;
    int id;
};

inline bool operator<(const tsob &a, const tsob &b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.end > b.end;
}

const int maxn = 200005;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
vector<tsob> sobs;
int n, m;
ll l[maxn], r[maxn];
int answer[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf(LLD LLD, &l[i], &r[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        sobs.pb({l[i + 1] - r[i], r[i + 1] - l[i], i});
    }
    for (int i = 0; i < m; i++)
    {
        ll a;
        scanf(LLD, &a);
        sobs.pb({a, -1, i});
    }
    sort(all(sobs));
    for (auto x : sobs)
    {
//         cout << x.x << ' ' << x.end << endl;
        if (!q.empty() && q.top().first < x.x)
        {
            printf("No\n");
            return 0;
        }
        if (x.end == -1)
        {
            if (!q.empty())
            {
                answer[q.top().second] = x.id;
                q.pop();
            }
        } else
        {
            q.push({x.end, x.id});
        }
    }
    if (!q.empty())
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    for (int i = 0; i < n - 1; i++) printf("%d ", answer[i] + 1);
	return 0;
}