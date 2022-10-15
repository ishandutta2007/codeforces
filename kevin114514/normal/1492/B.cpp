#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=b[i-1];
            if(a[i]>a[b[i-1]])
                b[i]=i;
        }
        int l=1,r=n;
        while(l<=r)
        {
            for(int i=b[r];i<=r;i++)
                cout<<a[i]<<" ";
            r=b[r]-1;
        }
        puts("");
    }
    return 0;
}