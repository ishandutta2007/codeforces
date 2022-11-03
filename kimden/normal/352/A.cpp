#include <iostream>

using namespace std;

int main()
{
    int n;
    int n5,n0;
    int a[1000];
    int i;
    cin>>n;
    n5=0;
    n0=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i-1];
        if(a[i-1]==5)
        {n5++;}else{n0++;}
    }
    n5=(int)(n5/9);
    if(n0>0)
    {
        if(n5==0)
        {
            cout<<"0";
            return 0;
        }
        while(n5>0)
        {
            cout<<"555555555";
            n5--;
        }
        for(i=1;i<=n0;i++)
        {
            cout<<"0";
        }
    }else
    {
        cout<<"-1";
    }
    return 0;
}