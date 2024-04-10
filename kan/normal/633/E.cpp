#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define left left_sdf

using ii = pair<int, int>;

const int maxn = 1000006;

priority_queue<ii> bestbest, top;
priority_queue<ii, vector<ii>, greater<ii>> left;

int n, k;
int a[maxn], b[maxn];
int ans[maxn];
int x[2 * maxn], y[2 * maxn];
bool killed[2 * maxn];

void add(int i)
{
    bestbest.push({min(x[i], y[i]), i});
    left.push({x[i], i});
    top.push({y[i], i});
    killed[i] = false;
}

int main()
{
    scanf("%d%d", &n, &k);
//     n = 1000000;
//     k = n / 2;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i] *= 100;
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
//     for (int i = 0; i < n; i++) a[i] = 100;
//     for (int i = 0; i < n; i++) b[i] = 100;
    int kv = 0;
    for (int i = n - 1; i >= 0; i--)
    {
//         cout << "i = " << i << endl;
        {
        int best = b[i];
        while (!left.empty())
        {
            if (killed[left.top().se])
            {
                left.pop();
                continue;
            }
            if (left.top().fi < a[i])
            {
                best = max(best, y[left.top().se]);
                killed[left.top().se] = true;
                left.pop();
            } else break;
        }
            x[kv] = a[i];
            y[kv] = best;
            add(kv);
            kv++;
        }
        {
            int best = a[i];
        while (!top.empty())
        {
            if (killed[top.top().se])
            {
                top.pop();
                continue;
            }
            if (top.top().fi > b[i])
            {
                best = max(best, x[top.top().se]);
                killed[top.top().se] = true;
                top.pop();
            } else break;
        }
            x[kv] = best;
            y[kv] = b[i];
            add(kv);
            kv++;
        }
        while (!bestbest.empty())
        {
            if (killed[bestbest.top().se])
            {
                bestbest.pop();
                continue;
            }
            ans[i] = bestbest.top().fi;
            break;
        }
    }
//     for (int i = 0; i < n; i++) printf("%d ", ans[i]);
//     printf("\n");
    sort(ans, ans + n);

    ld cnk = (ld)n / k;
    ld c = 1;
    ld answer = 0;
    for (int i = 0; i + k <= n; i++) 
    {
        answer += ans[i] * c;
        if (i + k < n)
        {
            c /= (n - i - 1);
            c *= (n - i - k);
        }
    }
    cout.precision(20);
    cout << answer / cnk << endl;
    return 0;
}