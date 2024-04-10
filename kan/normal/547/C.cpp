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

const int MAX = 500005;
const int maxn = 200005;

int a[maxn];
vector<int> divs[MAX];
bool bad[MAX];
int m[MAX], kv[MAX];
int n, q;
bool stand[maxn];
ll answer;
int curn;

void add(int x, int t)
{
    if (t == -1)
    {
        for (auto d : divs[x])
        {
            kv[d] += t;
        }
    }
    answer += t * curn;
//     cout << "add " << t << ' ' << curn << endl;
    for (auto d : divs[x])
    {
        answer += t * m[d] * kv[d];
//         cout << "addd " << d << ' ' << m[d] << ' ' << (-1) * t * m[d] * kv[d] << endl;
    }

    if (t == 1)
    {
        for (auto d : divs[x])
        {
            kv[d] += t;
        }
    }
}

int main()
{
    for (int i = 2; i < MAX; i++) m[i] = 1;
    for (int i = 2; i < MAX; i++) if (!bad[i])
    {
//         cout << i << ' ' << m[i] << endl;
        m[i] *= -1;
        for (ll j = (ll)2 * i; j < MAX; j += i)
        {
            bad[j] = true;
            if (j % ((ll)i * i) == 0) m[j] = 0;
            else m[j] *= -1;
        }
    }
//     cout << m[6] << endl;
    for (int i = 2; i < MAX; i++)
    {
        for (int j = 1; i * j < MAX; j++) divs[i * j].pb(i);
    }
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        stand[i] = false;
    }
    curn = 0;
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        if (stand[x])
        {
            curn--;
            add(a[x], -1);
        } else
        {
            add(a[x], 1);
            curn++;
        }
        stand[x] = !stand[x];
        printf(LLD "\n", answer);
//         cout << curn << endl;
    }
	return 0;
}