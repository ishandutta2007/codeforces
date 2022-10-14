#include <bits/stdc++.h>
#define maxn 100005
#define db(x) cout << #x ": " << (x) << '\n';
using namespace std;

int n,ans,d,a[maxn],h[maxn];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /// freopen("a.in","r",stdin);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i] >> h[i];

    d=-(1<<31);
    for(int i=1; i<=n; i++){

        if(i==1){ ans=1; d=a[i]; continue; }

        if(i==n){ cout << ans + 1 << '\n'; return 0; }

        if(a[i]-h[i]>d){ ans++; d=a[i]; continue; }

        if(a[i]+h[i]<a[i+1]){ ans++; d=a[i]+h[i]; continue; }

        d=a[i];
    }

    cout << ans << '\n';

    return 0;
}