#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 200001;

vector<vector<int> > to(MAX_N);
vector<vector<bool> > type(MAX_N);
int n, s[MAX_N], t[MAX_N], down[MAX_N], fl[MAX_N], k;
vector<int> ans;

void dfs(int p, int f, int d, int pr)
{
    down[p] = d;
    fl[p] = f;
    for (int i = 0; i < to[p].size(); i++)
        if (to[p][i] != pr)
        {
            k += type[p][i];
            dfs(to[p][i], f + 1, d + type[p][i], p);
        }
}

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
        scanf("%d%d", &s[i], &t[i]);
    for (int i = 0; i < n - 1; i++)
    {
        s[i]--, t[i]--;
        to[s[i]].push_back(t[i]);
        type[s[i]].push_back(true);
        type[t[i]].push_back(false);
        to[t[i]].push_back(s[i]);
    }
    k = 0;
    dfs(0, 0, 0, -1);
    int m = n;
    for (int i = 0; i < n; i++)
        m = min(m, n - 1 + 2 * down[i] - k - fl[i]);
    for (int i = 0; i < n; i++)
        if (m == n - 1 + 2 * down[i] - k - fl[i])
            ans.push_back(i + 1);
    sort(ans.begin(), ans.end());
    cout << m << endl;
    for (int i : ans)
        cout << i << " ";
    return 0;
}