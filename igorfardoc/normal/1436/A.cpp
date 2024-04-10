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
        int n, m;
        cin >> n >> m;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            sum += a;
        }
        if(m == sum)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}