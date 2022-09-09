#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 100005;

vector<int> v, answer;
int a[maxn], b[maxn];
int n, m;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int j = 0; j < m; j++) scanf("%d", &b[j]);
    int prev = -1;
    int k1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != prev) k1++;
        prev = a[i];
    }
    prev = -1;
    int k2 = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] != prev) k2++;
        prev = b[i];
    }
    int cur1 = 0;
    int cur2 = 0;
    if (k1 > k2 || (k1 == k2 && b[m - 1] == 0))
    {
        prev = a[0];
        cur1++;
        printf("%d", 1);
    } else
    {
//         cerr << "sf" << endl;
        prev = b[0];
        cur2++;
        printf("%d", n + 1);
    }
    v.resize(0);
    v.push_back(prev);
    while (cur1 < n || cur2 < m)
    {
        if (cur1 < n && a[cur1] == prev)
        {
            cur1++;
            printf(" %d", cur1);
        } else if (cur2 < m && b[cur2] == prev)
        {
            cur2++;
            printf(" %d", n + cur2);
        } else if (cur1 < n)
        {
            prev = a[cur1];
            cur1++;
            printf(" %d", cur1);
        } else
        {
            prev = b[cur2];
            cur2++;
            printf(" %d", n + cur2);
        }
        v.push_back(prev);
    }
    prev = v[0];
    for (int i = 0; i < v.size(); i++) if (v[i] != prev)
    {
        answer.push_back(i);
        prev = v[i];
    }
    if (prev == 1) answer.push_back(v.size());
    printf("\n%d\n", answer.size());
    for (int i = 0; i < answer.size(); i++) printf("%d ", answer[i]);
    printf("\n");
    return 0;
}