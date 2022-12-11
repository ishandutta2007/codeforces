#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

vector<vector<int> > g;
vector<int> subtree;

void dfs(int v)
{
    subtree[v] = 1;
    for (int to : g[v]) {
        dfs(to);
        subtree[v] += subtree[to];
    }
}

vector<double> ans;

void dfs_ans(int v)
{
    for (int to : g[v]) {
        ans[to] = ans[v] + 1 + 0.5 * (double)(subtree[v] - subtree[to] - 1);
        dfs_ans(to);
    }
}

int main()
{

    //ifstream cin("input.txt");

    int n;
    scanf("%d", &n);

    g.resize(n);
    subtree.resize(n);

    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        g[p].pb(i);
    }

    dfs(0);

    ans.resize(n);
    dfs_ans(0);

    for (int i = 0; i < n; ++i) {
        printf("%.1f ", ans[i] + 1);
    }
    cout << "\n";

}