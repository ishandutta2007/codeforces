#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        int n;
        cin >> n;
        string mass;
        cin >> mass;
        int ans = 0;
        int last = -1;
        for(int i = 0; i < n; i++)
        {
            if(last == -1)
            {
                if(mass[i] == 'A')
                {
                    last = 0;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                last++;
                if(mass[i] == 'A')
                {
                    last = 0;
                }
                else
                {
                    ans = max(ans, last);
                }
            }
        }
        cout << ans << endl;
    }
}