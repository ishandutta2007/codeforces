#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>n>>k;

        for(int i=0;i<n;i++)cin>>a[i];
        if(k==1){cout<<(n-1)/2<<endl;continue;}
        int ans=0;
        for(int i=1;i+1<n;i++)if(a[i]>a[i-1]+a[i+1])ans++;
        cout<<ans<<endl;
    }
    return 0;
}