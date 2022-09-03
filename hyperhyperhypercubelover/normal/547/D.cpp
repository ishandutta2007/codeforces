#include <stdio.h>
#include <algorithm>
#include <vector>

int n;
struct xsort
{
    int x, y, num;
    bool operator < (const xsort &r) const {if (x != r.x) return x < r.x; return y < r.y;}
}xs[200010];
struct ysort
{
    int x, y, num;
    bool operator < (const ysort &r) const {if (y != r.y) return y < r.y; return x < r.x;}
}ys[200010];
int px, py;
bool flag;
std :: vector <int> list[200010];
char ans[200010];

void dfs(int x, int state)
{
    int i;
    ans[x] = state;
    for (i = 0; i < list[x].size(); i++)
    {
        if (ans[list[x][i]]) continue;
        dfs(list[x][i], 3-state);
    }
}

int main()
{
    int i, a, b;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &a, &b);
        xs[i].x = ys[i].x = a;
        xs[i].y = ys[i].y = b;
        xs[i].num = ys[i].num = i;
    }
    std :: sort(xs+1, xs+n+1);
    std :: sort(ys+1, ys+n+1);
    
    for (i = 1; i <= n; i++)
    {
        if (px != xs[i].x)
        {
            px = xs[i].x;
            flag = false;
        }
        if (flag)
        {
            list[xs[i].num].push_back(xs[i-1].num);
            list[xs[i-1].num].push_back(xs[i].num);
            flag = false;
        }
        else flag = true;
    }
    for (i = 1; i <= n; i++)
    {
        if (py != ys[i].y)
        {
            py = ys[i].y;
            flag = false;
        }
        if (flag)
        {
            list[ys[i].num].push_back(ys[i-1].num);
            list[ys[i-1].num].push_back(ys[i].num);
            flag = false;
        }
        else flag = true;
    }
    
    for (i = 1; i <= n; i++) if (ans[i] == 0) dfs(i, 1);
    for (i = 1; i <= n; i++)
    {
        if (ans[i] == 1) putchar('b');
        if (ans[i] == 2) putchar('r');
    }
}