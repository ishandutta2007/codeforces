#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pr[200009];
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
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pr[i]=pr[i-1];
            if(a[i]<i)pr[i]++;
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=i)continue;
            if(a[i]>0)ans+=pr[a[i]-1];
        }
        cout<<ans<<endl;

    }


    return 0;

}