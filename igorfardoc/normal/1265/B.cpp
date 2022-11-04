#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<char> ret(n);
        ret[0] = '1';
        int * mass = new int[n];
        pair<int, int> * sortmass = new pair<int, int>[n];
        for(int i = 0; i < n; i++)
        {
            cin >> mass[i];
            sortmass[i] = make_pair(mass[i], i);
        }
        sort(sortmass, sortmass + n);
        int l = sortmass[0].second;
        int r = sortmass[0].second;
        for(int i = 2; i <= n; i++)
        {
            int id = sortmass[i - 1].second;
            if(id > r)
            {
                r = id;
            }
            if(id < l)
            {
                l = id;
            }
            if(r - l + 1 == i)
            {
                ret[i - 1] = '1';
            }
            else
            {
                ret[i - 1] = '0';
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout << ret[i];
        }
        cout << endl;
    }
}