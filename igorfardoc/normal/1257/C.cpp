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
        pair<int, int> * mass = new pair<int, int>[n];
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            mass[i] = make_pair(a, i);
        }
        sort(mass, mass + n);
        int min1 = 1000000;
        for(int i = 0; i < n - 1; i++)
        {
            if(mass[i].first == mass[i + 1].first)
            {
                min1 = min(min1, mass[i + 1].second - mass[i].second + 1);
            }
        }
        if(min1 == 1000000)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << min1 << endl;
        }
    }
}