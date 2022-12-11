#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    vector <int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    long long ans = 0;
    int pos = 1;
    for (int i = 0; i < m; i++)
    {
        long long x = a[i] - pos;
        if (x < 0) x += n;
        ans += x;
        pos = a[i];
    }

    cout << ans;

}