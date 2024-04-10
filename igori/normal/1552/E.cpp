#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n * k);
    for (int i = 0; i < n * k; i++)
        cin >> a[i], a[i]--;
    int rows = (n + k - 2) / (k - 1);
    vector<int> L(n, -1), R(n, -1);
    while (rows--)
    {
        int pos = 0;
        while (pos < n * k)
        {
            vector<int> posit(n, -1);
            while (pos < n * k)
            {
                if (posit[a[pos]] == -1)
                    posit[a[pos]] = pos;
                else if (L[a[pos]] == -1)
                {
                    L[a[pos]] = posit[a[pos]];
                    R[a[pos]] = pos;
                    break;
                }
                pos++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << L[i] + 1 << " " << R[i] + 1 << "\n";
}