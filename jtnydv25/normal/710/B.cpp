#include <bits/stdc++.h>
using namespace std;
int x[500005];
#define ll long long
int main()
{
    int n;
    cin>>n;
    ll s = 0;
    for(int i = 1;i<=n;i++)
        scanf("%d",&x[i]),s+=x[i];
    sort(x+1,x+n+1);
    ll mn = (1LL<<60);
    ll s1 = 0, a = 0;
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
        ll b = n-a;
        ll temp = (s-2*s1 + (a-b)*1ll*x[i]);
        if(temp < mn)
        {
            mn = temp;
            ans = x[i];
        }
        a++;
        s1+=x[i];
    }
    cout<<ans;
}