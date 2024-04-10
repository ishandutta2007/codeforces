#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

deque<int> v[2];
int n, q;

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n / 2; i++)
        v[0].push_back(2 * i), v[1].push_back(2 * i + 1);
    long long sdv = 0;
    int p1 = 0;
    int p2 = 1;
    for (int i = 0; i < q; i++)
    {
        int f, x;
        scanf("%d", &f);
        if (f == 1)
        {
            scanf("%d", &x);
            if (x == 0)
                continue;
            if (x < 0)
            {
                x *= -1;
                if (x % 2 != 0)
                {
                    int l = v[p1].front();
                    v[p1].pop_front();
                    v[p1].push_back(l);
                    swap(p1, p2);
                    x -= 1;
                }
                sdv -= x;
                continue;
            }
            if (x % 2 != 0)
            {
                int l = v[p2].back();
                v[p2].pop_back();
                v[p2].push_front(l);
                swap(p1, p2);
                x -= 1;
            }
            sdv += x;
        }
        else
            swap(p1, p2);
    }
    vector<int> a, a1, a2;
    for (int i : v[p1])
        a1.push_back(i);
    for (int i : v[p2])
        a2.push_back(i);
    for (int i = 0; i < n / 2; i++)
        a.push_back(a1[i]), a.push_back(a2[i]);
    vector<int> ans;
    ans.resize(n);
    bool rt = (sdv < 0);
    sdv = abs(sdv);
    sdv %= n;
    if (rt)
    {
        for (int i = sdv; i < n; i++)
            ans[i - sdv] = a[i];
        for (int i = n - sdv; i < n; i++)
            ans[i] = a[sdv - n + i];
    }
    else
    {
        for (int i = 0; i < n - sdv; i++)
            ans[i + sdv] = a[i];
        for (int i = 0; i < sdv; i++)
            ans[i] = a[n - sdv + i];
    }
    for (int i : ans)
        cout << i + 1 << " ";
    return 0;
}