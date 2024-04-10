#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10],b[109];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(a[i]!=b[i])ans++;
        }
        int res=1;
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n;i++)if(a[i]!=b[i])res++;
        ans=min(ans,res);
        cout<<ans<<endl;

    }

    return 0;

}