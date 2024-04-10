#include <bits/stdc++.h>
using namespace std;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(a[n]<a[n-1]){cout<<-1<<endl;continue;}
        bool bl=true;
        for(int i=2;i<=n;i++)if(a[i]<a[i-1])bl=false;
        if(bl){cout<<0<<endl;continue;}
        if(a[n]<0){cout<<-1<<endl;continue;}
        cout<<n-2<<endl;
        for(int i=1;i<=n-2;i++)cout<<i<<" "<<n-1<<" "<<n<<endl;

    }
    return 0;
}