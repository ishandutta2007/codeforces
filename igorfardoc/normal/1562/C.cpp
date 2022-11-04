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
        string s;
        cin >> s;
        bool ok = false;
        for(int i = 0; i < n; i++)
        {
            if(i < (n - 1) / 2 + 1 && s[i] == '0')
            {
                cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << '\n';
                ok = true;
                break;
            }
            if(i >= n / 2 && s[i] == '0')
            {
                cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
                ok = true;
                break;
            }
        }
        if(!ok)
        {
            cout << 1 << ' ' << n / 2 * 2 << ' ' << 1 << ' ' << n / 2 << '\n';
        }
    }
}