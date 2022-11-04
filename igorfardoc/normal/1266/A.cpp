#include<bits/stdc++.h>
using namespace std;
int int1(char c)
{
    if(c == '0')
    {
        return 0;
    }
    if(c == '1')
    {
        return 1;
    }
    if(c == '2')
    {
        return 2;
    }
    if(c == '3')
    {
        return 3;
    }
    if(c == '4')
    {
        return 4;
    }
    if(c == '5')
    {
        return 5;
    }
    if(c == '6')
    {
        return 6;
    }
    if(c == '7')
    {
        return 7;
    }
    if(c == '8')
    {
        return 8;
    }
    if(c == '9')
    {
        return 9;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        bool nullhere = false;
        bool chet = false;
        int sum = 0;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == '0' && !nullhere)
            {
                nullhere = true;
            }
            else
            {
                int a = int1(str[j]);
                if(a % 2 == 0)
                {
                    chet = true;
                }
                sum += a;
            }
        }
        if(nullhere && chet && (sum % 3 == 0))
        {
            cout << "red" << endl;
        }
        else
        {
            cout << "cyan" << endl;
        }
    }
}