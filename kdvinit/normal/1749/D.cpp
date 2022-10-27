/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 998244353;
const int N = 3e5 + 1;
int prim[N];

void siv()
{
    for(int i=0; i<N; i++) prim[i]=1;
    prim[0]=0; prim[1]=0;

    for(int i=2; i<N; i++)
    {
        if(prim[i]==0) continue;
        for(int j=i*i; j<N; j+=i) prim[j]=0;
    }
}

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

int LCM(int x, int y)
{
    if(x==0 || y==0) { cout<<"Fuckkk"<<endl; return 1; }

    int z = GCD(x, y);
    x/=z;
    y/=z;
    z = (x*y);
    return z;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int ans=m;
    int cur=1;

    int fans=0;
    ans%=mod;

    for(int i=2; i<=n; i++)
    {
        if(cur!=-1)
        {
            if(prim[i]==1) cur = cur*i;

            if(cur>m) { ans=0; cur=-1; }
            else
            {
                int tmp = (m/cur);
                tmp=(tmp%mod);
                ans=(ans%mod);
                ans = (ans*tmp)%mod;
            }
        }

        int tot = Power(m, i)%mod;
        int cur_ans = (tot-ans)%mod;
        fans = (fans+cur_ans)%mod;
    }

    if(fans<0) fans+=mod;
    cout<<fans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    siv();
    solve();
    return 0;
}