#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        int len = a.length();
        int j = 0;
        set<char> ok;
        while (j < len)
        {
            if(j != len - 1)
            {
                if (a[j] == a[j + 1])
                {
                    j += 2;
                }
                else
                {
                    ok.insert(a[j]);
                    j++;
                }
            }
            else
            {
                ok.insert(a[j]);
                j++;
            }
        }
        set<char>::iterator it = ok.begin();
        for(;it != ok.end(); it++)
        {
            cout << (*it);
        }
        cout << endl;
    }
}