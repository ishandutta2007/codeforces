#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i != (n); i++)
#define fi first
#define se second
#define pb push_back
#define sz size()

int a[150000];
int l[5000], r[5000];
int n, m;

long long go(int j)
{
    int b[150000];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    for (int i = 0; i < m; i++)
    {
        if (l[i] <= j && j <= r[i])
            continue;
        for (int k = l[i]; k <= r[i]; k++)
        {
            b[k]--;
        }
    }
    int mx = -1e9, mn = 1e9;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, b[i]);
        mn = min(mn, b[i]);
    }
    return mx - mn;
}

long long go(int j, int p)
{
    vector<int> changes;
    int b[150000];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    for (int i = 0; i < m; i++)
    {
        if (l[i] <= j && j <= r[i])
            continue;
        for (int k = l[i]; k <= r[i]; k++)
        {
            b[k]--;
        }
        changes.push_back(i + 1);
    }
    cout << changes.size() << endl;
    for (int i = 0; i < changes.size(); i++)
    {
        cout << changes[i] << " ";
    }
    exit(0);
    int mx = -1e9, mn = 1e9;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, b[i]);
        mn = min(mn, b[i]);
    }
    return mx - mn;
}

int main()
{
    cin >> n >> m;
    int max_ = -1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > max_)
        {
            max_ = a[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= max_)
        {
            answer = max(answer, go(i));
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= max_)
        {
            if (go(i) == answer)
            {
                cout << answer << endl;
                go(i, 1);
            }
        }
    }
}