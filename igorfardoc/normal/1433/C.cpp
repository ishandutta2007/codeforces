#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int max1 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            max1 = max(max1, a[i]);
        }
        bool ok = false;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == max1)
            {
                if(i == 0 && a[i + 1] != max1)
                {
                    cout << i + 1 << "\n";
                    ok = true;
                    break;
                }
                if(i == n - 1 && a[n - 2] != max1)
                {
                    cout << n << "\n";
                    ok = true;
                    break;
                }
                if(i != n - 1 && i != 0 && (a[i + 1] != max1 || a[i - 1] != max1))
                {
                    cout << i + 1 << "\n";
                    ok = true;
                    break;
                }
            }
        }
        if(!ok)
        {
            cout << "-1\n";
        }
    }
}