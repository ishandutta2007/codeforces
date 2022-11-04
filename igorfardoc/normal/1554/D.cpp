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
        int n;
        cin >> n;
        if(n == 1)
        {
            cout << "a\n";
            continue;
        }
        string res = "";
        int am = n / 2;
        for(int i = 0; i < am; i++)
        {
            res += 'a';
        }
        res += 'b';
        if(n % 2 == 1)
        {
            res += 'c';
        }
        for(int i = 0; i < am - 1; i++)
        {
            res += 'a';
        }
        cout << res << '\n';
    }
}