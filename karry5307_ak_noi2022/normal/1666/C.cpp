#include <cstdio>
#include <algorithm>
using namespace std;
pair<int, int> p[4];
int Ans[105][5], top;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
int main()
{
    int Xmax = 1, Xmin = 1, Ymax = 1, Ymin = 1;
    for (int i = 1; i <= 3; i++)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + 4);
    if (p[1].first != p[2].first)
    {
        top++;
        Ans[top][1] = p[1].first;
        Ans[top][2] = p[1].second;
        Ans[top][3] = p[2].first;
        Ans[top][4] = p[1].second;
        p[1].first = p[2].first;
    }
    if (p[3].first != p[2].first)
    {
        top++;
        Ans[top][1] = p[3].first;
        Ans[top][2] = p[3].second;
        Ans[top][3] = p[2].first;
        Ans[top][4] = p[3].second;
        p[3].first = p[2].first;
    }
    sort(p + 1, p + 4, cmp);
    if (p[1].second != p[3].second)
    {
        top++;
        Ans[top][1] = p[1].first;
        Ans[top][2] = p[1].second;
        Ans[top][3] = p[3].first;
        Ans[top][4] = p[3].second;
    }
    printf("%d\n", top);
    for (int i = 1; i <= top; i++)
    {
        printf("%d %d %d %d\n", Ans[i][1], Ans[i][2], Ans[i][3], Ans[i][4]);
    }
}