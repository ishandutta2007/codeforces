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
        bool eq = true;
        map<int, vector<int> > d;
        set<int> there;
        int v = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(i > 0)
            {
                eq = eq && (a[i] == a[i - 1]);
                there.insert(a[i]);
                d[a[i]].push_back(i);
            }
        }
        if(eq)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        auto it = there.begin();
        for(; it != there.end(); it++)
        {
            int type1 = (*it);
            if(type1 != a[0])
            {
                for(int i = 0; i < d[type1].size(); i++)
                {
                    cout << v + 1 << " " << d[type1][i] + 1 << "\n";
                }
                v = d[type1][0];
            }
        }
        if(there.find(a[0]) != there.end())
        {
            for(int i = 0; i < d[a[0]].size(); i++)
            {
                cout << v + 1 << " " << d[a[0]][i] + 1 << "\n";
            }
        }
    }
}