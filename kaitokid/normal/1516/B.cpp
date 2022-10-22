#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[2009],pr[2009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k=0;
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i];k^=a[i];pr[i]=k;}

        bool ans=false;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            if((pr[i]==k)&&((pr[n-1]^pr[j-1])==k))ans=true;
        for(int i=0;i<n;i++)
            if(pr[i]==(k^pr[i]))ans=true;
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}