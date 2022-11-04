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
        int max1 = -1;
        map<int, int> d;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            d[a[i]]++;
            max1 = max(d[a[i]], max1);
        }
        cout << max1 << '\n';

    }
}