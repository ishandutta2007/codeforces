#include <iostream>

using namespace std;

int main()
{
    int n,a[110],b[110],p=0,k=0;
    cin>>n;
    char c;
    for(int i=1;i<=n;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c;
            if(c=='.')
            {
                a[i]=j;
                b[j]=i;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
            p=1;
        if(b[i]==0)
            k=1;
    }
    if(k==1 && p==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(p==0)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<i<<" "<<a[i]<<endl;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" "<<i<<endl;
    }
    return 0;
}