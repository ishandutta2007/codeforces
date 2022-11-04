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
        vector<int> mass(n);
        for(int i = 0; i < n; i++)
        {
            cin >> mass[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                cout << mass[i + 1] << " ";
            }
            else
            {
                cout << -mass[i - 1] << " ";
            }
        }
        cout << "\n";
    }
}