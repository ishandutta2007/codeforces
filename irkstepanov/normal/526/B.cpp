#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

int ans = 0;
vector <int> maxim, a;
int n;

void dfs(int v, int get)
{
    //cout << v << " " << get << "\n";
    if (v * 2 >= n) return;
    if (a[v * 2] + maxim[v * 2] < get)
    {
        int delta = get - a[v * 2] - maxim[v * 2];
        ans += delta;
        dfs(v * 2, get - delta - a[v * 2]);
    }
    else dfs(v * 2, get - a[v * 2]);
    if (a[v * 2 + 1] + maxim[v * 2 + 1] < get)
    {
        int delta = get - a[v * 2 + 1] - maxim[v * 2 + 1];
        ans += delta;
        dfs(v * 2 + 1, get - delta - a[v * 2 + 1]);
    }
    else dfs(v * 2 + 1, get - a[v * 2 + 1]);
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;

    n = (1 << (n + 1));
    a.resize(n);

    maxim.assign(n, -1);

    for (int i = 2; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 1; i--)
    {
        if (i * 2 < n) maxim[i] = max(a[i * 2] + maxim[i * 2], a[i * 2 + 1] + maxim[i * 2 + 1]);
        else maxim[i] = 0;
    }

    dfs(1, maxim[1]);

    cout << ans << "\n";

}