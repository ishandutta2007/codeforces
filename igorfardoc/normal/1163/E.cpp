#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005, MX = 1E6 + 5;

int n, x = 0, a[N];
bool vis[MX];
vector<int> vec, ans;
int basis[20];
int d = 20;
int sz = 0;

void add(int mask)
{
    int tmp = mask;
    for (int i = 0; i < d; i++) {
        if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

        if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
            basis[i] = mask;
            ++sz;
            vec.push_back(tmp);
            return;
        }

        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
}

void DFS(int u, int it = 0)
{
    ans.push_back(u);
    vis[u] = true;
    if (it == (1 << x) - 1)
        return;
    for (int &v : vec)
        if (!vis[u ^ v])
        {
            DFS(u ^ v, it + 1);
            return;
        }
}

int main()
{
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    int pt = 0;
    for (int i = 1; i < 20; i++)
    {
        for (; pt < n && a[pt] < (1 << i); pt++)
            add(a[pt]);
        if (sz == i)
            x = i;
    }
    for(int i = 0; i < d; i++) {
        basis[i] = 0;
    }
    sz = 0;
    vec.clear();
    for (int i = 0; i < n && a[i] < (1 << x); i++)
        add(a[i]);
    printf("%d\n", x);
    DFS(0);
    for (int &v : ans)
        printf("%d ", v);
}