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
        string s;
        cin >> s;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'L' || s[i] == 'R')
            {
                cout << s[i];
                continue;
            }
            cout << (char)('U' + 'D' - s[i]);
        }
        cout << '\n';
    }
}