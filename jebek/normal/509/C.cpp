#include <iostream>

using namespace std;

struct big
{
    int a[700];
    int n;
    big(int b=0)
    {
        for(int i=0;i<700;i++)
            a[i]=0;
        n=1;
    }
    void normalize()
    {
        for(int i=0;i<n;i++)
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
        while(a[n]>0)
        {
            a[n+1]+=a[n]/10;
            a[n]=a[n]%10;
            n++;
        }
    }
    void shot()
    {
        while(n>1)
        {
            if(a[n-1]!=0)
                break;
            n--;
        }
    }
    void print()
    {
        shot();
        for(int i=n-1;i>-1;i--)
            cout<<a[i];
        cout<<endl;
    }
};

big A(0);
big B(0);
big zero(0);
int sum;

big ok(int x)
{
    A.a[0]++;
    A.normalize();
    sum=0;
    for(int i=0;i<A.n;i++)
        sum+=A.a[i];
    if(sum<=x)
    {
        for(int i=0;sum<x;i++)
        {
            if(i==A.n)
                A.n++;
            while(A.a[i]<9 && sum<x)
                A.a[i]++,sum++;
        }
        return A;
    }
    B=zero;
    B.n=A.n;
    int p=0;
    while(sum>=x)
    {
        sum-=A.a[p];
        p++;
    }
    while(p<A.n && A.a[p]==9)
        p++;
    if(p==A.n)
    {
        B.a[B.n]=1;
        B.n++;
    }
    else
    {
        for(int i=p;i<A.n;i++)
            B.a[i]=A.a[i];
        B.a[p]++;
    }
    sum=0;
    for(int i=0;i<B.n;i++)
        sum+=B.a[i];
    for(int i=0;sum<x;i++)
        for(;B.a[i]<9 && sum<x;sum++)
            B.a[i]++;
    return B;
}

int main()
{
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        A=ok(x);
        A.print();
    }
}