//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;

int main()
{
    string a, b;
    cin >> a >> b;
    a = "000"+a;
    b = "000"+b;
    int na = a.size(), nb = b.size();
    bool czy = true;
    while(czy)
    {
        czy = false;
        for(int i=1; i<na; i++)
        {
            if(a[i-1]=='0' && a[i]=='1')
            {
                int ti = i;
                while(a[ti]=='1')
                    ti++;
                if(ti<=i+1)
                    continue;
                czy = true;
                //cout << i << " " << ti << "\n";
                if((ti-i)%2)
                    ti--;
                for(int j=i-1; j<ti; j++)
                {
                    if((j-i-1)%2)
                        a[j] = '0';
                    else
                        a[j] = '1';
                }
                a[ti-1] = '0';
                i = ti-2;
            }
        }
        for(int i=na-1; i>=1; i--)
        {
            if(a[i-1]=='0' && a[i]=='1')
            {
                int ti = i;
                while(a[ti]=='1')
                    ti++;
                if(ti<=i+1)
                    continue;
                czy = true;
                //cout << i << " " << ti << "\n";
                if((ti-i)%2)
                    ti--;
                for(int j=i-1; j<ti; j++)
                {
                    if((j-i-1)%2)
                        a[j] = '0';
                    else
                        a[j] = '1';
                }
                a[ti-1] = '0';
                i = ti-2;
            }
        }        
    }
    czy = true;
    while(czy)
    {
        czy = false;
        for(int i=1; i<nb; i++)
        {
            if(b[i-1]=='0' && b[i]=='1')
            {
                int ti = i;
                while(b[ti]=='1')
                    ti++;
                if(ti<=i+1)
                    continue;
                czy = true;
                //cout << i << " " << ti << "\n";
                if((ti-i)%2)
                    ti--;
                for(int j=i-1; j<ti; j++)
                {
                    if((j-i-1)%2)
                        b[j] = '0';
                    else
                        b[j] = '1';
                }
                b[ti-1] = '0';
                i = ti-2;
            }
        }
        for(int i=nb-1; i>=1; i--)
        {
            if(b[i-1]=='0' && b[i]=='1')
            {
                int ti = i;
                while(b[ti]=='1')
                    ti++;
                if(ti<=i+1)
                    continue;
                czy = true;
                //cout << i << " " << ti << "\n";
                if((ti-i)%2)
                    ti--;
                for(int j=i-1; j<ti; j++)
                {
                    if((j-i-1)%2)
                        b[j] = '0';
                    else
                        b[j] = '1';
                }
                b[ti-1] = '0';
                i = ti-2;
            }
        }        
    }
    string res = "";
    if(a.size() < b.size())
    {
        int k = b.size() - a.size();
        for(int i=0; i<k; i++)
            res += "0";
        a = res + a;
    }
    else
    {
        int k = a.size() - b.size();
        for(int i=0; i<k; i++)
            res += "0";
        b = res + b;        
    }
    //cout << a << " " << b << "\n";
    if(a==b)
        cout << "=";
    else if(a>b)
        cout << ">";
    else
        cout << "<";
    return 0;
}