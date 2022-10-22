#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009];
int main()
{
ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=0;i<n+2;i++)
        cin>>a[i];
    sort(a,a+n+2);
    ll sum=0;
    for(int i=0;i<n;i++)
            sum+=a[i];
    if(sum==a[n])
    {
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
        continue;
    }
    sum+=a[n];
    ll d=sum-a[n+1];
    bool res=false;
    for(int i=0;i<n+1;i++)if(a[i]==d){res=true;break;}
    if(!res){cout<<-1<<endl;continue;}
    for(int i=0;i<n+1;i++)
    {
        if(a[i]==d&&res){res=false;continue;}
        cout<<a[i]<<" ";
    }
    cout<<endl;

    }
    return 0;
}