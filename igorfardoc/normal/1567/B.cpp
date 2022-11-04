#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> mass(1000000);
    for(int i = 1; i <= 1000000; i++)
    {
        mass[i] = mass[i - 1] ^ i;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int val = mass[a - 1] ^ b;
        if(val == a)
        {
            cout << a + 2 << '\n';
        }
        else if(val == 0)
        {
            cout << a << '\n';
        }
        else
        {
            cout << a + 1 << '\n';
        }
    }
}