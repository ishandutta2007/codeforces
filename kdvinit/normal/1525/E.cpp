/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int Power(int $a,int $b)
{
    int $result=1; $a%=mod;
    while($b) {   if($b%2==1)  $result*=$a;     $a*=$a;     $a%=mod;     $result%=mod;    $b/=2; }
    return $result;
}

int Mod_Inv(int $a)
{
    $a%=mod; $a=Power($a,mod-2); return $a;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int nf = 1;
    for(int i=1; i<=n; i++)
    {
        nf*=i;
        nf%=mod;
    }

    int a[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }

    int ans = 0;

    for(int j=1; j<=m; j++)
    {
        vector<int> tmp;
        for(int i=1; i<=n; i++)
        {
            tmp.push_back(a[i][j]);
        }
        sort(tmp.begin(), tmp.end());

        int val = 1;
        for(int i=0; i<n; i++)
        {
            int x = tmp[i]-i-1;
            val*=x;
            val%=mod;
        }

        ans+=nf;
        ans-=val;
        ans%=mod;

        while(ans<0) ans+=mod;
        ans%=mod;
    }

    ans%=mod;
    ans*=Mod_Inv(nf);
    ans%=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}