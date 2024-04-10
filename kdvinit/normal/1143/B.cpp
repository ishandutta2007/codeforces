#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();

    int a[n+1];
    for(int i=1;i<=n;i++) a[i]=s[i-1]-48;

    long long int ans=pow(9,n-1),tmp=a[1],tans;
    if(a[1]==1) { cout<<ans<<endl; return 0; }

    ans*=(a[1]-1);
    //cout<<ans<<endl;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==1) continue;
        if(a[i]==0) break;
        tans=tmp*(a[i]-1)*pow(9,n-i);
        ans=max(ans,tans);
        tmp*=a[i];
        //cout<<ans<<endl;
    }
    ans=max(ans,tmp);

    cout<<ans<<endl;
    return 0;
}