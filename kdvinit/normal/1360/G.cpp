#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b,k=0;
        cin>>n>>m>>a>>b;
        if(n*a!=m*b) { cout<<"NO"<<endl; continue; }
        if(a>m) { cout<<"NO"<<endl; continue; }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            if(k+a<=m)
            {
                for(int j=1;j<=k;j++) cout<<0;
                for(int j=k+1;j<=k+a;j++) cout<<1;
                for(int j=k+a+1;j<=m;j++) cout<<0;
                k=(k+a)%m;
            }
            else
            {
                for(int j=1;j<=k+a-m;j++) cout<<1;
                for(int j=a+k-m+1;j<=k;j++) cout<<0;
                for(int j=k+1;j<=m;j++) cout<<1;
                k=k+a-m;
            }
            cout<<endl;
        }
    }
    return 0;
}