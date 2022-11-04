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
        int n;
        cin >> n;
        long long a = 0;
        long long b = 0;
        long long now = 2;
        for(int i = 1; i <= n; i++)
        {
            if(i < n / 2 || i == n)
            {
                a += now;
            }
            else
            {
                b += now;
            }
            now *= 2;
        }
        cout << abs(a - b) << endl;
    }
}