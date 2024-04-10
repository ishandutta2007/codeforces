#include <iostream>

using namespace std;
int a[1002];
int b[1002];
int n;

int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    }
for(int i=1;i<=n;i++)
{
    cin>>b[i];
    }

    int sumXor=0;
    for(int i=1;i<=n;i++)
    {
        int Xora=a[i];
        int Xorb=b[i];
        if(sumXor<Xora+Xorb)
            sumXor=Xora+Xorb;
        for(int j=i+1;j<=n;j++)
        {
            Xora=Xora|a[j];
            Xorb=Xorb|b[j];
        if(sumXor<Xora+Xorb)
            sumXor=Xora+Xorb;
        }
    }

    cout<<sumXor<<'\n';

    return 0;
}