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
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        if(sum % n != 0)
        {
            cout << "-1\n";
            continue;
        }
        int need = sum / n;
        for(int i = 0; i <= n; i++)
        {
            if(i == n || a[i] > need)
            {
                cout << n - i << '\n';
                break;
            }
        }
    }
}