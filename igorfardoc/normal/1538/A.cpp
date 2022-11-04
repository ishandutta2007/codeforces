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
        int min1 = 101;
        int minid = -1;
        int max1 = 0;
        int maxid = -1;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if(a < min1)
            {
                min1 = a;
                minid = i;
            }
            if(a > max1)
            {
                max1 = a;
                maxid = i;
            }
        }
        int res = n;
        res = min(res, max(minid, maxid) + 1);
        res = min(res, n - min(minid, maxid));
        res = min(res, min(minid, maxid) + 1 + n - max(minid, maxid));
        cout << res << '\n';
    }
}