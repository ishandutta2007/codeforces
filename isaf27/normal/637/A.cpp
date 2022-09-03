#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX_N = 1000001;

int n, a[1001], u[MAX_N];

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    for (int i = 0; i < MAX_N; i++)
        u[i] = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        u[a[i]]++;
    int m = 0;
    for (int i = 0; i < MAX_N; i++)
        m = max(u[i], m);
    for (int i = 0; i < MAX_N; i++)
        u[i] = 0;
    for (int i = 0; i < n; i++)
    {
        u[a[i]]++;
        if (u[a[i]] == m)
        {
            cout << a[i];
            return 0;
        }
    }
    return 0;
}