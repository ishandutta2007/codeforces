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
    string s;
    cin >> s;
    for(int i = 2; i < s.size(); i++)
    {
        if(((s[i - 1] - 'A') + (s[i - 2] - 'A')) % 26 + 'A' != s[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}