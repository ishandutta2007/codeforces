#include <iostream>
#include<algorithm>
#include<set>

using namespace std;

long long n,a[300000],t[300000],m,ans;
set<long long>s;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=1)
            a[i]-=a[1];
    }
    a[1]=0;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        t[x]++;
    }
    if(t[n]>t[1])
    {
        for(int i=1;i<=n;i++)
            a[i]=a[n]-a[i];
        reverse(a+1,a+n+1);
        reverse(t+1,t+n+1);
    }
    if(t[n]==t[1])
    {
        ans=(t[1]*2-1)*a[n];
        int i=2;
        while(i<n && t[i]>t[1]*2-1 && (t[i]>=t[i-1] || i==2))
            i++;
        ans+=a[i-1];
      //  cout<<i<<" "<<endl;
        if(i==n && t[i-1]==2*t[1])
        {
            for(int i=1;i<n;i++)
                s.insert(a[i+1]-a[i]);
            if(s.size()>1)
            {
                cout<<-1<<endl;
                return 0;
            }
            else
            {
                cout<<ans<<endl;
                return 0;
            }
        }
        i=n-1;
        while(i>1 && t[i]>t[1]*2-1 && (t[i]>=t[i+1] || i==n-1))
            i--;
        ans+=a[n]-a[i+1];
        cout<<ans<<endl;
        return 0;
    }
    ans=t[n]*2*a[n];
    for(int i=2;i<n;i++)
        ans+=(t[i]-2*t[n])*(a[i]-a[i-1]);
    cout<<ans<<endl;
}