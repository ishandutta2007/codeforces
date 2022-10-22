#include <iostream>

using namespace std;
int a[100009],b[100009];
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        bool pl=false,pp=false,ans=true;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            if(b[i]<a[i]&&pp==false)ans=false;
            if(b[i]>a[i]&&pl==false)ans=false;
            if(a[i]==1)pl=true;
            if(a[i]==-1)pp=true;
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
        }

    return 0;
}