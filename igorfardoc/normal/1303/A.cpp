#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen ("garland.out", "w", stdout);
    //freopen ("garland.in", "r", stdin);
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        int n;
        string mass;
        cin >> mass;
        n = mass.length();
        int fir = -1;
        int sec = -2;
        for(int j = 0; j < n; j++)
        {
            if(mass[j] == '1')
            {
                sec = j;
            }
            if(fir == -1 && mass[j] == '1')
            {
                fir = j;
            }
        }
        int ans = 0;
        for(int i = fir; i <= sec; i++)
        {
            if(mass[i] == '0')
            {
                ans++;
            }
        }
        cout << ans << endl;

    }
}