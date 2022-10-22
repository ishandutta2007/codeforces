#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll mod = 1e9+7;
const int maxx = 100010;
int a[maxx]; // 
bool pri[maxx];
int p[maxx],n[maxx];
int cnt = 0,cnt1 = 0;
void prime()
{
    for(int i=2;i<=maxx;i++)
    {
        if(!pri[i])
            a[cnt1++] = i;
        for(int j=0;(j<cnt1 && (ll)i*a[j]<=maxx);j++)
        {
            pri[i*a[j]] = 1;
            if(i%a[j] == 0)
                break;
        }
    }
}
void solve(ll x)
{
    ll ans = 1;
    for(int i=0;a[i]*a[i] <= x;i++)
    {
        if(x%a[i] == 0)
        {
            p[++cnt] = a[i];
            n[cnt] = 0;
            while(x%a[i] == 0)
            {
                n[cnt]++;
                x /= a[i];
            }
        }
    }
    if(x!=1){
        p[++cnt] = x;
        n[cnt] = 1;
    }
    return ;
}
ll pow_mod(ll a,ll b)
{
    ll ans = 1;
    while(b){
        if(b&1)
           ans = ans*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    ll x, n;
    prime();
    cin>>x>>n;
    solve(x);
    ll ans = 1;
    for(int i=1;i<=cnt;i++)
    {
        //cout<<p[i]<<" "<<endl;
        int flag = 0;
        ll k = 1ll*p[i];
        ll k2 = 1ll*p[i];
        while(k <= n){
            ll now = n / k;
            if(n/k < k2){
                flag = 1;
            }
            ans *= pow_mod(k2 , now);
            ans %= mod;
            k *= 1ll*k2;
            if(flag){
                break;
            }
            //cout<<k<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}