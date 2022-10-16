/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    char s[n+1],t[n+1];
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>t[i];

    int freq[27]={0};
    for(int i=1;i<=n;i++) freq[s[i]-96]++;
    for(int i=1;i<=n;i++) freq[t[i]-96]++;

    for(int i=1;i<=26;i++)
    {
        if(freq[i]%2==0) continue;
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;

    int a[1001],b[1001],cnt=0;

    for(int i=1;i<=n;i++)
    {
        if(s[i]==t[i]) continue;
        int flag=0;
        for(int j=i+1;j<=n;j++)
        {
            if(s[i]!=s[j]) continue;
            swap(s[j],t[i]);
            flag=1;
            a[++cnt]=j;
            b[cnt]=i;
            break;
        }

        if(flag==1) continue;

        for(int j=i+1;j<=n;j++)
        {
            if(s[i]!=t[j]) continue;
            swap(s[i+1],t[j]);
            a[++cnt]=i+1;
            b[cnt]=j;
            swap(s[i+1],t[i]);
            a[++cnt]=i+1;
            b[cnt]=i;
            break;
        }
    }

    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i]<<" "<<b[i]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}