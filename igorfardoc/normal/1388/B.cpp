#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int eight = (n - 1) / 4 + 1;
        for(int i = 0; i < n - eight; i++)
        {
            cout << "9";
        }
        for(int i = 0; i < eight; i++)
        {
            cout << "8";
        }
        cout << endl;
    }
}
// 6 10 14 15 33
//51