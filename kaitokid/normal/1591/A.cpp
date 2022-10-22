#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[300];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int ans=1;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        ans+=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]==0&&a[i-1]==0){ans=-1;break;}
            if(a[i]==1&&a[i-1]==1){ans+=5;continue;}
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}