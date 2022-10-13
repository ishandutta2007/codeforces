#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

long long n;
int a[500000];
int b[500000];
long long ans = 0;
long long pos[500000];

bool check(int take)
{
    //cout << take << " : ";
    for (int i = 1; i <= n; i++)
    {
        int p = pos[i] - take - i + 1;
        //cout << p << " ";
        if (p > 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        pos[b[i]] = i + 1;
    }
    long long wait = 1;
    long long ok = 1;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            while (i < n)
            {
                if (b[i] == wait)
                {
                    wait++;
                    i++;
                }
                else
                {
                    ok = 0;
                    wait = 1;
                    break;
                }
            }
            break;
        }
    }
    if (ok)
    {
        long long op = n - wait + 1;
        //cout << op << endl;
        for (int i = wait; i <= n; i++)
        {
            if (pos[i] - i + wait > 0)
                ok = 0;
        }
        if (ok == 1)
        {
            cout << op;
            return 0;
        }
    }
    long long l = -1, r = n;
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r + n << endl;
}