#include <bits/stdc++.h>
using namespace std;

int n,k,ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>k;
        ans=max(ans,min(k-1,1000000-k));
    }

    cout<<ans<<'\n';

    return 0;
}