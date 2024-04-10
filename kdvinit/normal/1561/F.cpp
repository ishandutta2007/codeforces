/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long

const int mod = 998244353;
const int Fact_Length = 5e5 + 1;     //Max length

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int $a) { return Power($a,mod-2); }

int Factorial[Fact_Length];
// It make the above Factorial[i] = i! array
int Make_Factorial()
{
   Factorial[0]=1;
   for(int i=1;i<Fact_Length;i++) { Factorial[i]=(i*Factorial[i-1])%mod; } return 0;
}
int Implement_Make_Factorial=Make_Factorial();      //To Implement Make_Factorial

// Takes n&r as input and Returns : nCr%mod
int nCr(int $n,int $r)
{
   if($n<$r || $n<0 || $r<0) return 0;
   //if($n>Fact_Length) { cout<<"Error"<<endl; return; }
   int $ans=(Factorial[$n]*Mod_Inv(Factorial[$r]))%mod;
   $ans=($ans*Mod_Inv(Factorial[$n-$r]))%mod;
   return $ans;
}

const int mx = 2e5+5;
int cnt;

ordered_set os;

void solve()
{
    int n, m;
    cin>>n>>m;

    int N = 2*n - 1;
    int R = n;

    vector<int> num;
    for(int i=1; i<=m; i++)
    {
        int x, y;
        cin>>x>>y;
        num.push_back(y);
    }

    cnt=0;

    vector<int> rem;
    map<int, int> mp;
    for(int i=m-1; i>=0; i--)
    {
        int y = num[i];
        int a = *os.find_by_order(y);
        int b = *os.find_by_order(y-1);
        if(mp[a]==0) cnt ++;
        mp[a]=1;
        os.erase(b);
        rem.push_back(b);
    }
    
    for(int x: rem) os.insert(x);

    N-=cnt;
    int ans = nCr(N, R);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1; i<=mx; i++) os.insert(i);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}