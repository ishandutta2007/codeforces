#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

vector <vector <bool> > ok;
vector <bool> met;
int n;

void dfs(int v)
{
    met[v] = true;
    for (int i = 0; i < n; i++)
        if (ok[v][i] && !met[i]) dfs(i);
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int x0, y0;
    cin >> n >> x0 >> y0;

    vector <int> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        x[i] -= x0;
        y[i] -= y0;
    }

     ok.assign(n, vector <bool> (n, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
    {
        if (!y[i] && !y[j]) ok[i][j] = true;
        else if (!y[i] || !y[j]) ok[i][j] = false;
        else if (x[i] * y[j] == x[j] * y[i]) ok[i][j] = true;
        else ok[i][j] = false;
    }

    met.assign(n, false);

    int ans = 0;

    for (int i = 0; i < n; i++)
        if (!met[i])
    {
        dfs(i);
        ++ans;
    }

    cout << ans << "\n";

}