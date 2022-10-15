#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    char s[200];
    for(int i=0;i<200;i++) s[i]='a';

    for(int i=0;i<200;i++) cout<<s[i];
    cout<<endl;

    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        if(s[x]=='a') s[x]='b';
        else s[x]='a';
        for(int j=0;j<200;j++) cout<<s[j];
        cout<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}