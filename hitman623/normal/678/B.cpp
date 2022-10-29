#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,o=0;
    cin>>n;
    if(n%400==0 || (n%100!=0 && n%4==0))
    {
        n++;o=2;
        while(!(o%7==0 && (n%400==0 || (n%100!=0 && n%4==0))))
        {
            if(n%400==0 || (n%100!=0 && n%4==0)) o+=2;
                else o+=1;
            n++;
            //cout<<n<<"  "<<o<<endl;
        }
        cout<<n;

    }
    else
    {   n++;o=1;
        while(o%7!=0 || (n%400==0 || (n%100!=0 && n%4==0)))
        {
            if(n%400==0 || (n%100!=0 && n%4==0)) o+=2;
                else o+=1;
            n++;
        }
        cout<<n;
    }
    return 0;
}