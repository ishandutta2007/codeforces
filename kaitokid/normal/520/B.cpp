#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,q=0;
    cin>>a>>b;


    if(a>b)

    {
        cout<<a-b;
        return 0;
    }

     q+=ceil(log2(ceil((b/(a+0.0)))+0.0));

    a*=pow(2,q);

    int y=q;
    while(a!=b)
    {
        y+=(a-b)/pow(2,q);

        a-=floor((a-b)/pow(2,q))*pow(2,q);

        q--;
    }
    cout<<y;
    return 0;
}