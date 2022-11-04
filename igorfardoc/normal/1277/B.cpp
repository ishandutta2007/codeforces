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
        set<int, greater<int> > s;
        for(int i = 0; i < n; i++)
        {
            int zn;
            cin >> zn;
            s.insert(zn);
        }
        int ans = 0;
        while(s.size() != 0)
        {
            int zn = *s.begin();
            if(zn % 2 == 1)
            {
                s.erase(s.begin());
            }
            else
            {
                s.erase(s.begin());
                s.insert(zn / 2);
                ans++;
            }
        }
        cout << ans << endl;
    }
}