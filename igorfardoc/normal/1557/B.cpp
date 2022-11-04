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
        int n, k;
        cin >> n >> k;
        vector<pair<int, int> > a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(i != 0 && a[i].second != a[i - 1].second + 1)
            {
                res++;
            }
        }
        if(res < k)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}