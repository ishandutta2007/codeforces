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

int n;
int d[50000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d, d + n);
    cout << d[n - 1];
    for (int i = 1; i <= d[n - 1]; i++)
    {
        if (d[n - 1] % i == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[j] == i)
                {
                    d[j] = 0;
                    break;
                }
            }
        }
    }
    sort(d, d + n);
    cout << " " << d[n - 1];
}