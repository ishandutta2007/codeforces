#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int n,a[maxn],ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=n; i++){
        ans+=abs(a[i]);
    }

    cout<<ans<<'\n';

    return 0;
}