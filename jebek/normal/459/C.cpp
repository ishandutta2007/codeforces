#include <iostream>

using namespace std;

long long a,n,k,d,ans[2000];

bool check()
{
    long long a=k;
    if(a>=n)
        return false;
    for(int i=1;i<d;i++)
    {
        a*=k;
        if(a>=n)
            return false;
    }
    return true;
}

int main()
{
    cin>>n>>k>>d;
    if(check())
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int j=0;j<n;j++)
        ans[j]=j;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[j]%k+1<<" ";
            ans[j]/=k;
        }
        cout<<endl;
    }
}