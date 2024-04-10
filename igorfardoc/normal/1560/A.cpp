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
        int k;
        cin >> k;
        int i = 0;
        while(true)
        {
            if(i % 3 == 0 || i % 10 == 3)
            {
                i++;
                continue;
            }
            if((--k) == 0)
            {
                cout << i << '\n';
                break;
            }
            i++;
        }
    }
}