/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9+7;
const int N = 2e6+100;
const int N2 = 1e6;
const int M = 5e5+5;
int val[N]={0};

int Factorial[M];
int Make_Factorial()
{
   Factorial[0]=1;
   for(int i=1;i<M;i++) { Factorial[i]=(i*Factorial[i-1])%mod; } return 0;
}
int Implement_Make_Factorial=Make_Factorial();      //To Implement Make_Factorial

int upd(int l, int r)
{
    val[l]++;
    val[r+2]--;
}

int get_ways()
{
    int ans=(Factorial[val[0]]*Factorial[val[1]])%mod;
    for(int i=2; i<N; i++)
    {
        val[i]+=val[i-2];
        ans*=Factorial[val[i]];
        ans%=mod;
    }
    return ans;
}

int val2[N2], tmpr[N2], tmpl[N2], len[N2];
void get_val2()
{
    val2[0]=0; tmpr[0]=0;   tmpl[0]=0;      len[0]=0;
    val2[1]=(val[N2]+val[N2+1])%mod;    tmpr[1]=val2[1]; tmpl[1]=val2[1];   len[1]=val2[1];

    for(int i=2; i<N2; i++)
    {
        int m = i-1;

        int tt = (m*(val[N2+i-1]+val[N2+i-2]))%mod;
        tmpr[i] = (tmpr[i-2]+tt)%mod;

        tt = (m*(val[N2+i-1]+val[N2+i]))%mod;
        tmpl[i] = (tmpl[i-2]+tt)%mod;
        //if(i<7) cout<<i<<" -> "<<tmpl[i]<<" "<<tmpr[i]<<endl;

        len[i] = (len[i-2] + (val[N2+i-1]+val[N2+i]) + (val[N2+i-1]+val[N2+i-2]))%mod;
        val2[i] = (val2[i-2]+tmpr[i]+tmpl[i]+len[i])%mod;
        tmpr[i] = (tmpr[i]+len[i])%mod;
        tmpl[i] = (tmpl[i]+len[i])%mod;
    }
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; int l=a[i]-1; upd(N2-l, N2+l); }

    int ways = get_ways();

    get_val2();
    int ans=0;
    for(int i=1; i<=n; i++) { ans+=val2[a[i]-1]; ans%=mod; }
    ans%=mod;
    if(ans<0) ans+=mod;

    cout<<ans<<" "<<ways<<endl;
    return;

    for(int i=-5; i<=5; i++) cout<<val[N2+i]<<" ";
    cout<<endl;
    for(int i=0; i<=5; i++) cout<<val2[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}