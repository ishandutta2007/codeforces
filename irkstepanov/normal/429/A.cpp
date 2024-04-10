#include <iostream>
#include <vector>

using namespace std;

int n;
int init[100500];
int goal[100500];
vector <int> ans;
int met[100500];

vector <vector <int> > g;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

void dfs (int v, int chet, int nech)
{
    met[v] = 1;
    if ((init[v] + chet) % 2 != goal[v])
    {
        ans.push_back (v);
        chet++;
    }
    for (int i = 0; i < g[v].size(); i++)
        if (met[g[v][i]] == 0) dfs (g[v][i], nech, chet);
}

int main()
{

    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back (b);
        g[b].push_back (a);
    }

    for (int i = 1; i <= n; i++)
        cin >> init[i];
    for (int i = 1; i <= n; i++)
        cin >> goal[i];
    for (int i = 1; i <= n; i++)
        met[i] = 0;

    dfs (1, 0, 0);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";

}