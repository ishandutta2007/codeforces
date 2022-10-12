#include <iostream>
#include <vector>

using namespace std;

int check(vector<long long> a)
{
    for (int i = 0; i + 1 < a.size(); i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0;
        }
        a[i + 1] -= a[i];
        a[i] = 0;
    }
    if (a.back() == 0)
        return 1;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (check(a))
    {
        cout << "YES\n";
        return;
    }
    if (n == 1)
    {
        cout << "NO\n";
        return;
    }
    swap(a[0], a[1]);
    if (check(a))
    {
        cout << "YES\n";
        return;
    }
    swap(a[0], a[1]);
    swap(a[n - 2], a[n - 1]);
    if (check(a))
    {
        cout << "YES\n";
        return;
    }
    swap(a[n - 2], a[n - 1]);
    vector<long long> p(n), s(n);
    vector<long long> b = a;
    p[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        if (p[i - 1] == -1 || b[i - 1] > b[i])
        {
            p[i] = -1;
        }
        else
        {
            b[i] -= b[i - 1];
            b[i - 1] = 0;
            p[i] = b[i];
        }
    }
    b = a;
    s[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i + 1] == -1 || b[i + 1] > b[i])
        {
            s[i] = -1;
        }
        else
        {
            b[i] -= b[i + 1];
            b[i + 1] = 0;
            s[i] = b[i];
        }
    }
    for (int i = 1; i + 2 < n; i++)
    {
        vector<long long> c = {p[i - 1], a[i], a[i + 1], s[i + 2]};
        if (p[i - 1] == -1 || s[i + 2] == -1)
        {
            continue;
        }
        swap(c[1], c[2]);
        if (check(c))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}