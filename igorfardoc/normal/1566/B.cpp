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
        string s;
        cin >> s;
        int prev = -1;
        int am = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0' && prev == -1)
            {
                prev = i;
            }
            if(s[i] == '1' && prev != -1)
            {
                prev = -1;
                ++am;
            }
        }
        am += (prev != -1);
        if(am == 0)
        {
            cout << "0\n";
            continue;
        }
        if(am == 1)
        {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
}