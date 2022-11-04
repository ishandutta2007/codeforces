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
    int t;
    cin >> t;
    while(t--)
    {
        int c, d;
        cin >> c >> d;
        if(c == 0 && d == 0)
        {
            cout << "0\n";
            continue;
        }
        if(c == d)
        {
            cout << "1\n";
            continue;
        }
        if(abs(c - d) % 2 == 1)
        {
            cout << "-1\n";
            continue;
        }
        cout << "2\n";
    }
}