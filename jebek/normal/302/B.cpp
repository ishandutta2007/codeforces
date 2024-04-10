#include<iostream>

using namespace std;

int main()
{
    long long c,t,a[100000],v,g=0;
    long n,m;
    cin>>n>>m;
    cin>>c>>t;
    a[0]=c*t;
    for(long i=1;i<n;i++)
    {
        cin>>c>>t;
        a[i]=a[i-1]+c*t;
    }
    for(long i=0;i<m;i++)
    {
        cin>>v;
        while(a[g]<v)
            g++;
        cout<<g+1<<endl;
    }
}