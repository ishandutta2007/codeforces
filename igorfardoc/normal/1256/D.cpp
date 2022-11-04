#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        long long n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int firstone = -1;
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '1')
            {
                firstone = i;
                break;
            }
        }
        if(firstone == -1)
        {
            cout << str << endl;
        }
        else
        {
            bool ok = false;
            for(int i = firstone + 1; i < n; i++)
            {
                if(str[i] == '1')
                {
                    continue;
                }
                int amountone = i - firstone;
                if(k >= amountone)
                {
                    firstone++;
                    k-= amountone;
                }
                else
                {
                    int idnul = i - k;
                    ok = true;
                    for(int j = 0; j < firstone; j++)
                    {
                        cout << '0';
                    }
                    for(int j = firstone; j <= i; j++)
                    {
                        if(j == idnul)
                        {
                            cout << '0';
                        }
                        else
                        {
                            cout << '1';
                        }
                    }
                    for(int j = i + 1; j < n; j++)
                    {
                        cout << str[j];
                    }
                    cout << endl;
                    break;
                }
            }
            if(!ok)
            {
                for(int i = 0; i < n; i++)
                {
                    if(i < firstone)
                    {
                        cout << '0';
                    }
                    else
                    {
                        cout << '1';
                    }
                }
                cout << endl;
            }
        }
    }
}