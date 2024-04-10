#include <iostream>
#include <vector>

using namespace std;

int a[500], b[500], n, m;
vector<int> graph[200];

bool ok(int i, int j)
{
    if (b[i] <= a[j])
        return 1;
    if (b[j] <= a[i])
        return 1;
    if (a[i] <= a[j] && b[j] <= b[i])
        return 1;
    if (a[j] <= a[i] && b[i] <= b[j])
        return 1;
    return 0;
}

int c[2000];
int answ = 1;

void go(int x, int f)
{
    c[x] = f;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];
        if (c[y] == 0)
        {
            go(y, 3 - f);
        }
        if (c[y] == f)
        {
            answ = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    a[0] = 1;
    b[0] = n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (ok(i, j) == 0)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    for (int i = 0; i <= m; i++)
    {
        if (c[i] == 0)
        {
            go(i, 1);
        }
    }
    if (answ == 0)
    {
        cout << "Impossible";
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        if (c[i] == 1)
            cout << "i";
        else
            cout << "o";
    }
}