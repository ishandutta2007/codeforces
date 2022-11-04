#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> mass(n);
        set<int> all;
        for(int i = 0; i < n; i++)
        {
            cin >> mass[i];
            all.insert(mass[i]);
        }
        if(all.size() > k)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> mass1;
        for(int i = 0; i < 100; i++)
        {
            set<int>::iterator it = all.begin();
            for(; it != all.end(); it++)
            {
                mass1.push_back(*it);
            }
            for(int j = 0; j < k - all.size(); j++)
            {
                mass1.push_back(1);
            }
        }
        cout << mass1.size() << endl;
        for(int i = 0; i < mass1.size(); i++)
        {
            cout << mass1[i] << " ";
        }
        cout << endl;
    }
}