/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

int f1(int x,int a[],int n)
{
    int ans=0;
    for(int i=1;i<=n;i++) { if(a[i]%2!=x) ans++; x=(x+1)%2; }
    return ans;
}

int f2(int x,int y,int a[],int b[],int n)
{
    int ans=0;
    for(int i=1;i<=n;i++) { if(a[i]%2!=x || b[i]%2!=y) ans++; x=(x+1)%2; y=(y+1)%2; }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n,m;
    cin>>n>>m;
    char x;

    if(n>=4 && m>=4)
    {
        string s;
        for(int i=1;i<=n;i++) cin>>s;
        cout<<-1<<endl;
    }
    else if(n==1 || m==1)
    {
        for(int i=1;i<=n;i++) { for(int j=1;j<=m;j++) cin>>x; }
        cout<<0<<endl;
    }
    else if(n==2)
    {
        int a[m+1]={0};
        for(int i=1;i<=m;i++) { cin>>x; if(x=='1') a[i]++; }
        for(int i=1;i<=m;i++) { cin>>x; if(x=='1') a[i]++; }
        int ans=min(f1(0,a,m),f1(1,a,m));
        cout<<ans<<endl;
    }
    else if(n==3)
    {
        int a[m+1]={0},b[m+1]={0};
        for(int i=1;i<=m;i++) { cin>>x; if(x=='1') a[i]++; }
        for(int i=1;i<=m;i++) { cin>>x; if(x=='1') { a[i]++; b[i]++; } }
        for(int i=1;i<=m;i++) { cin>>x; if(x=='1') b[i]++; }

        int ans1=min(f2(0,0,a,b,m),f2(0,1,a,b,m));
        int ans2=min(f2(1,0,a,b,m),f2(1,1,a,b,m));
        int ans=min(ans1,ans2);

        cout<<ans<<endl;
    }
    else if(m==2)
    {
        int a[n+1]={0};
        for(int i=1;i<=n;i++) { cin>>x; if(x=='1') a[i]++; cin>>x; if(x=='1') a[i]++; }
        int ans=min(f1(0,a,n),f1(1,a,n));
        cout<<ans<<endl;
    }
    else if(m==3)
    {
        int a[n+1]={0},b[n+1]={0};
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x=='1') a[i]++;
            cin>>x;
            if(x=='1') { a[i]++; b[i]++; }
            cin>>x;
            if(x=='1') b[i]++;
        }

        int ans1=min(f2(0,0,a,b,n),f2(0,1,a,b,n));
        int ans2=min(f2(1,0,a,b,n),f2(1,1,a,b,n));
        int ans=min(ans1,ans2);

        cout<<ans<<endl;
    }

	return 0;
}