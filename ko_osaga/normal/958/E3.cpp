#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x;
    int y;
    int c;
    int ind;
    point(){};
    point (int a, int b, int _c, int d): x(a), y(b), c(_c), ind(d){};
};
int ans[10101];
point V[20202];
void solve(int from, int to)
{
    /*
    printf("%d %d\n", from, to);
    puts("==");
    for(int i=from; i<=to; ++i)
    {
        printf("%d ", V[i].c);
    }
    puts("==");
    */
    if(to-from==1)
    {
        if(V[to].c == 1)
            ans[V[to].ind] = V[from].ind;
        else
            ans[V[from].ind] = V[to].ind;
        return;
    }
    auto ptr = min_element(V+from, V+to+1, [](const point& a, const point& b){ return a.x < b.x; });
    swap(V[from], *ptr);
    int cnt = V[from].c;
    sort(V+from+1, V+to+1, [&](const point &a, const point & b)
    {
        return (a.x - V[from].x) * (b.y-V[from].y)
            - (a.y - V[from].y) * (b.x-V[from].x) < 0;
    });
    for(int i=from+1; i<=to; ++i)
    {
        cnt += V[i].c;
        if(cnt == 0)
        {
            solve(from, i);
            solve(i+1, to);
            return;
        }
        if(cnt == V[from].c)
        {
            swap(V[i], V[from]);
            solve(from, i-1);
            solve(i, to);
            return;
        }
    }
    assert(false);
}
int N;
int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; ++i)
    {
        int x, y; scanf("%d%d", &x, &y);
        V[i] = point(x, y, 1, i);
    }
    for(int i=1; i<=N; ++i)
    {
        int x, y; scanf("%d%d", &x, &y);
        V[N+i] = point(x, y, -1, i);
    }
    solve(1, 2*N);
    for(int i=1; i<=N; ++i)
        printf("%d\n", ans[i]);
    return 0;
}