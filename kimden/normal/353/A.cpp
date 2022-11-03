#include <iostream>

using namespace std;

int main()
{
    int n,i,s1,s2;
    int u[100],d[100];
    cin>>n;
    s1=0;
    s2=0;
    for(i=0;i<n;i++)
    {
        cin>>u[i]>>d[i];
        u[i]=u[i]%2;
        d[i]=d[i]%2;
        s1=s1+u[i];
        s2=s2+d[i];
    }
    if((s1+s2)%2==1)
    {
        cout<<-1;
        return 0;
    }else if((s1%2==0)&&(s2%2==0))
    {
        cout<<0;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(u[i]!=d[i])
        {
            cout<<1;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}