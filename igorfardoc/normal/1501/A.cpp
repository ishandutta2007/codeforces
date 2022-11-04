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
        vector<int> b(n);
        vector<int> t(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> t[i];
        }
        int now = a[0] + t[0];
        for(int i = 0; i < n; i++)
        {
            if(i == n - 1)
            {
                cout << now << '\n';
                break;
            }
            int max1 = b[i];
            max1 = max(max1, now + (b[i] - a[i] - 1) / 2 + 1);
            now = max(max1, now);
            now += a[i + 1] - b[i] + t[i + 1];
        }
    }
}