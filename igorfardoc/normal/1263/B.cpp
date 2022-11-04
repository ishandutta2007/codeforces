#include<bits/stdc++.h>
using namespace std;
char str1(int c)
{
    if(c == 0)
    {
        return '0';
    }
    else if(c == 1)
    {
        return '1';
    }
    else if(c == 2)
    {
        return '2';
    }
    else if(c == 3)
    {
        return '3';
    }
    else if(c == 4)
    {
        return '4';
    }
    else if(c == 5)
    {
        return '5';
    }
    else if(c == 6)
    {
        return '6';
    }
    else if(c == 7)
    {
        return '7';
    }
    else if(c == 8)
    {
        return '8';
    }
    else if(c == 9)
    {
        return '9';
    }
}

int main()
{
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        int n;
        cin >> n;
        string * mass = new string[n];
        set<char> s;
        for(int i = 0; i <= 9; i++)
        {
            s.insert(str1(i));
        }
        for(int j = 0; j < n; j++)
        {
            cin >> mass[j];
            set<char>::iterator it = s.find(mass[j][0]);
            if(it != s.end())
            {
                s.erase(it);
            }
        }
        int ans = 0;
        for(int k = 0; k < n; k++)
        {
            for(int l = k + 1; l < n; l++)
            {
                if (mass[k] == mass[l])
                {
                    ans++;
                    mass[l][0] = *s.begin();
                    s.erase(s.begin());
                }
            }
        }
        cout << ans << endl;
        for(int i = 0; i < n; i++)
        {
            cout << mass[i] << endl;
        }
    }
}