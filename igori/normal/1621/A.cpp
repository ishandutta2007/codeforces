#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k > (n + 1) / 2)
        {
            cout << "-1\n";
            continue;
        }
        vector<string> s(n, string(n, '.'));
        for (int i = 0; i < k; i++)
            s[2 * i][2 * i] = 'R';
        for (int i = 0; i < n; i++)
            cout << s[i] << "\n";
    }
}