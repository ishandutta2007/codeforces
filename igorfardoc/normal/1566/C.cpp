#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int get(bool a0, bool a1)
{
    if(a0 && a1)
    {
        return 2;
    }
    if(a0 || a1)
    {
        if(a0)
        {
            return 1;
        }
    }
    return 0;
}

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
        string s1, s2;
        cin >> s1 >> s2;
        bool a0 = false;
        bool a1 = false;
        int am = 0;
        for(int i = 0; i < n; i++)
        {
            bool a0h = false;
            bool a1h = false;
            if(s1[i] == '0' || s2[i] == '0')
            {
                a0h = true;
            }
            if(s1[i] == '1' || s2[i] == '1')
            {
                a1h = true;
            }
            if(a0h && a1h)
            {
                am += 2 + get(a0, a1);
                a0 = false;
                a1 = false;
            }
            else if((a0h || a0) && (a1h || a1))
            {
                am += 2;
                a0 = false;
                a1 = false;
            }
            else
            {
                am += get(a0, a1);
                a0 = a0h;
                a1 = a1h;
            }
        }
        am += get(a0, a1);
        cout << am << '\n';
    }
}