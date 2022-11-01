#include <iostream>
#include<algorithm>

using namespace std;

int n,m,k,a[200],b[200];

int main()
{
    cin>>n>>m;
    k=m;
    if(n==1 && m==0)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    if(m==0 || n*9<m)
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    a[n-1]=1;
    m--;
    for(int i=0;i<n;i++){
        a[i]+=min(9,m);
        m-=min(9,m);
    }
    for(int i=0;i<n;i++)
    {
        b[i]+=min(k,9);
        k-=min(k,9);
    }
    for(int i=n-1;i>-1;i--)
        cout<<a[i];
    cout<<" ";
    for(int i=0;i<n;i++)
        cout<<b[i];
    cout<<endl;
}