#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        bool ok = false;
        for(int i = 0; i < str.length() - 1; i++)
        {
            if(str[i] == str[i + 1] && str[i] != '?')
            {
                cout << -1 << endl;
                ok = true;
                break;
            }
        }
        if(!ok)
        {
            for(int i = 0; i < str.length(); i++)
            {
                if(str[i] == '?')
                {
                    if(i == str.length() - 1 || str[i + 1] == '?')
                    {
                        if(i == 0 || str[i - 1] == 'a')
                        {
                            cout << 'b';
                            str[i] = 'b';
                        }
                        else
                        {
                            cout << 'a';
                            str[i] = 'a';
                        }
                    }
                    else
                    {
                        if(i == 0)
                        {
                            if(str[i + 1] == 'a')
                            {
                                cout << 'b';
                            }
                            else
                            {
                                cout << 'a';
                            }
                            continue;
                        }
                        if(str[i + 1] == str[i - 1])
                        {
                            if(str[i + 1] == 'a')
                            {
                                cout << 'b';
                            }
                            else
                            {
                                cout << 'a';
                            }
                        }
                        else
                        {
                            cout << char('a' + 'b' + 'c' - str[i - 1] - str[i + 1]);
                        }
                    }
                }
                else
                {
                    cout << str[i];
                }
            }
            cout << endl;
        }
    }
}