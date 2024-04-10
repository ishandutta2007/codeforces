#include <iostream>

using namespace std;

int main()
{
    long n,a[100005]={0},i,j;
    cin>>n;
    for(i=2;i<=n+1;++i)
    {
        if(a[i]==0)
        {
            a[i]=1;
            for(j=2*i;j<=n+1;j+=i)
                a[j]=2;
        }
    }
    if(n>2)
    {cout<<2<<endl;
    for(i=2;i<=n+1;++i)
        cout<<a[i]<<" ";}
        else
        {
            cout<<1<<endl<<1;
            if(n==2) cout<<" "<<1;
        }
    return 0;
}