/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n, k; 
    cin>>n>>k;
    k*=8; k/=n;
    int dif = 1;
    
    while(k--) { dif*=2; if(dif>n) break; }

    int a[n+1]; for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1); a[0]=-1;

    int ans=0; int freq[n+1];
    for(int i=1; i<=n; i++) { if(a[i-1]!=a[i]) ans++; freq[i]=ans; }
    ans=n;
    
    int j=1;
    for(int i=1; i<=n; i++)
    {
        while(j!=n+1 && freq[j]<freq[i]+dif) j++;
        int tmp = i-1 + n+1-j;
        ans=min(ans, tmp);
    }

    cout<<ans<<endl;
    return 0;
}