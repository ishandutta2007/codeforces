#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2009];
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
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
        if((a[i]%2==0)||(a[j]%2==0)){ans++;continue;}
        if((__gcd(a[i],a[j]))>1)ans++;}
        cout<<ans<<endl;

    }
    return 0;
}