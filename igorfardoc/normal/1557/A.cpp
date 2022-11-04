#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;



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
        sort(a.begin(), a.end());
        ll fir = 0;
        ll sec = a[n - 1];
        for(int i = 0; i < n - 1; i++)
        {
            fir += a[i];
        }
        cout << fixed << setprecision(20) << (ld)fir / (n - 1) + sec << '\n';
    }
}