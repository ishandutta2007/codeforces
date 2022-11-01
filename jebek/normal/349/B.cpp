#include <iostream>

using namespace std;

int a[10],p,MIN=10000000,n;

void dp(int k,int r)
{
    if(k!=0)
    {
        if(r==p)
        {
            for(int i=k;i>0;i--)
                cout<<p;
        }
        else if((k-1)*MIN+a[r]<=n)
        {
            n-=a[r];
            cout<<r;
            dp(k-1,r);
        }
        else
            dp(k,r-1);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=9;i++)
    {
        cin>>a[i];
        if(a[i]<=MIN)
        {
            MIN=a[i];
            p=i;
        }
    }
    if(MIN>n)
    {
        cout<<-1<<endl;
        return 0;
    }
    int k=n/MIN;
    dp(k,9);
}