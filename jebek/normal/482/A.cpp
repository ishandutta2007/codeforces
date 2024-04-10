#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<cstring>

using namespace std;

int n,k;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        if(i%2==1)
            cout<<i/2+1<<" ";
        else
            cout<<n-i/2+1<<" ";
    }
    if(k%2==0)
    {
        for(int i=n-k/2;i>k/2;i--)
            cout<<i<<" ";
    }
    else
    {
        for(int i=k/2+2;i<=n-k/2;i++)
            cout<<i<<" ";
    }
    cout<<endl;
}