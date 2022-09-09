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

const int maxn = 200005;
const int MOD = 1000000007;

vector<int> gr[maxn];
int ans[maxn], answer[maxn], to[maxn];
int n;

void go(int cur, int pr)
{
    ans[cur] = 1;
    for (auto e : gr[cur]) if (e != pr)
    {
        go(e, cur);
        ans[cur] = ((ll)ans[cur] * (ans[e] + 1)) % MOD;
    }
}

void calc(int cur, int pr, int fromup)
{
    answer[cur] = ((ll)(fromup + 1) * ans[cur]) % MOD;
    int prv = fromup + 1;
    for (auto e : gr[cur]) if (e != pr)
    {
        to[e] = prv;
        prv = ((ll)prv * (ans[e] + 1)) % MOD;
    }
    prv = 1;
    for (int i = (int)gr[cur].size() - 1; i >= 0; i--) if (gr[cur][i] != pr)
    {
        calc(gr[cur][i], cur, ((ll)to[gr[cur][i]] * prv) % MOD);
        prv = ((ll)prv * (ans[gr[cur][i]] + 1)) % MOD;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        scanf("%d", &a);
        a--;
        gr[a].pb(i + 1);
        gr[i + 1].pb(a);
    }
    go(0, -1);
//     cout << "SGd" << endl;
    calc(0, -1, 0);
    for (int i = 0; i < n; i++) printf("%d ", answer[i]);
    printf("\n");
	return 0;
}