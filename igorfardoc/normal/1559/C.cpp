#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if(a[0] == 1)
        {
            cout << n + 1 << ' ';
            for(int i = 0; i < n; i++)
            {
                cout << i + 1 << ' ';
            }
            cout << '\n';
        }
        else if(a[n - 1] == 0)
        {
            for(int i = 0; i < n; i++)
            {
                cout << i + 1 << ' ';
            }
            cout << n + 1 << '\n';
        }
        else
        {
            bool ok = false;
            for(int i = 0; i < n; i++)
            {
                cout << i + 1 << ' ';
                if(ok)
                {
                    continue;
                }
                if(a[i] == 0 && a[i + 1] == 1)
                {
                    cout << n + 1 << ' ';
                    ok = true;
                }
            }
            cout << '\n';
        }
    }
}