#include <bits/stdc++.h>

using namespace std;

const int N = 500000;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++)
            cout << i << " ";
        cout << 1 << "\n";
    }
}