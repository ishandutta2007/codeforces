/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;
const int N = 2e5+10;
int p2[N];

int calc(vector<int> a)
{
    int n = a.size();
    int m = 40;
    int cnt[m+1]={0};

    for(int i=0; i<n; i++)
    {
        int x = a[i];
        int y=0;
        while(x%2==0) { y++; x/=2; }
        cnt[y]++;
    }

    int suf[m+1]={0};
    for(int i=m-1; i>=0; i--) suf[i]=cnt[i]+suf[i+1];

    int ans=0;
    for(int i=0; i<m; i++)
    {
        int cur = cnt[i];
        int rem = suf[i+1];
        if(cur==0) continue;
        int tmp = ((p2[cur-1] - 1)*p2[rem])%mod;
        ans+=tmp;
        ans%=mod;
    }

    ans%=mod;   if(ans<0) ans+=mod;
    return ans;
}

void solve()
{
    int n, cnt0=0, cnt1=0;
    cin>>n;

    vector<int> a;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(x%2==1) cnt1++;
        else { cnt0++; x/=2; a.push_back(x); }
    }

    int ans = (p2[cnt0]*(p2[cnt1]-1))%mod;
    ans += calc(a); ans%=mod; if(ans<0) ans+=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    p2[0]=1;
    for(int i=1; i<N; i++) p2[i] = (p2[i-1]*2)%mod;
    solve();
    return 0;
}