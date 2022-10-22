#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int u=-1,mn=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            if(a[i+1]-a[i]<mn){mn=a[i+1]-a[i];u=i;}

        }
        cout<<a[u]<<" ";
        for(int i=u+2;i<n;i++)cout<<a[i]<<" ";
        for(int i=0;i<u;i++)cout<<a[i]<<" ";
        cout<<a[u+1]<<endl;
        }
    return 0;

}