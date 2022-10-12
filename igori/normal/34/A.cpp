#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int md = 1e9;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) md = min(md, abs(a[i] - a[(i + 1) % n]));
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i] - a[(i + 1) % n]) == md)
        {
            cout << i + 1 << " " << (i + 1) % n + 1 << "\n";
            return 0;
        }
    }
}