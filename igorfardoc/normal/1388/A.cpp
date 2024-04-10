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
        if(n <= 30)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if(n == 36)
        {
            cout << "5 6 10 15" << endl;
            continue;
        }
        if(n == 40)
        {
            cout << "6 3 10 21" << endl;
            continue;
        }
        if(n == 44)
        {
            cout << "6 7 10 21" << endl;
            continue;
        }
        cout << "6 10 14 " << n - 30 << endl;
    }
}
// 6 10 14 15 33
//51