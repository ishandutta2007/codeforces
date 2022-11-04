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
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int bef = -1;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i])
            {
                if(bef != -1)
                {
                    ans += i - bef - 1;
                }
                bef = i;
            }
        }
        cout << ans << "\n";
    }
}