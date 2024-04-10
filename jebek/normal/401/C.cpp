#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,k,a;

int main()
{
    cin>>n>>m;
    if(n>m+1 || m>n*2+2)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n==m+1)
    {
        for(int i=0;i<m;i++)
            cout<<"01";
        cout<<0<<endl;
        return 0;
    }
    if(m>n*2)
    {
        a=m-n*2;
        m=n*2;
    }
    k=m-n;
    for(int i=0;i<k;i++)
        cout<<110;
    for(int i=k;i<n;i++)
        cout<<10;
    for(int i=0;i<a;i++)
        cout<<1;
    cout<<endl;
}