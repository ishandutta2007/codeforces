#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,m;
LL a[1010];

void query(int x,int y,int z,LL &s)
{
    //s=Cout(x,y,z);
    cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
    cin>>s;
}

LL sum4(int a,int b,int c,int d)
{
    LL s;
    query(a,b,c,s);
    LL Max=s,Min=s;
    query(a,c,d,s);
    Max=max(Max,s),Min=min(Min,s);
    query(a,b,d,s);
    Max=max(Max,s),Min=min(Min,s);
    query(b,c,d,s);
    Max=max(Max,s),Min=min(Min,s);
    return Min+Max;
}

void init()
{
    LL a1234=sum4(1,2,3,4);
    LL a1235=sum4(1,2,3,5);
    LL a1245=sum4(1,2,4,5);
    LL a1345=sum4(1,3,4,5);
    LL a2345=sum4(2,3,4,5);
    LL sum=(a1234+a1235+a1245+a1345+a2345)/4LL;
    a[1]=sum-a2345;a[2]=sum-a1345;
    a[3]=sum-a1245;a[4]=sum-a1235;
    a[5]=sum-a1234;
}

int main()
{
    cin>>n;
    init();
    for (int i=6;i<=n;i++)
    {
        LL sum=sum4(i-3,i-2,i-1,i);
        a[i]=sum-a[i-3]-a[i-2]-a[i-1];
    }
    cout<<"! ";
    for (int i=1;i<n;i++)
        cout<<a[i]<<" ";
    cout<<a[n]<<endl;
    return 0;
}