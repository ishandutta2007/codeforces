/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int $Fact_Length = 500001;     //Max length here is 519160

/**Takes a&b as input and Returns : The power (a,b), (a^b)%mod **/
int Power(int $a,int $b)
{
    int $result=1; $a%=mod;
    while($b) {   if($b%2==1)  $result*=$a;     $a*=$a;     $a%=mod;     $result%=mod;    $b/=2; }
    return $result;
}

/** It give the modulo inverse of a, (1/a)%mod **/
int Mod_Inv(int $a)
{
    $a%=mod; $a=Power($a,mod-2); return $a;
}

int Factorial[$Fact_Length];

/** It make the above Factorial array to i! array**/
int Make_Factorial()
{
    Factorial[0]=1;
    for(int i=1;i<$Fact_Length;i++) { Factorial[i]=i*Factorial[i-1]; Factorial[i]%=mod; } return 0;
}
int Implement_Make_Factorial=Make_Factorial();      //To Implement Make_Factorial

/** Takes n&r as input and Returns : nCr%mod **/
int nCr(int $n,int $r)
{
    if($n<$r) return 0;
    int $ans=Factorial[$n]; $ans%=mod;
    $ans*=Mod_Inv(Factorial[$r]); $ans%=mod;
    $ans*=Mod_Inv(Factorial[$n-$r]); $ans%=mod;
    return $ans;
}

int Diff_Perm(vector<int> a)
{
    int n = a.size();
    map<int, int> mp;

    for(int i=0; i<n; i++) mp[a[i]]++;

    int ans = Factorial[n];
    for(auto itr: mp)
    {
        int cnt = itr.second;
        int tmp = Mod_Inv( Factorial[cnt] );
        ans*=tmp;
        ans%=mod;
    }

    return ans;
}


void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);
    int sum = 0;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum%n!=0)
    {
        cout<<0<<endl;
        return;
    }

    int eq = sum/n;

    int cntl=0;
    int cntr=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]<eq) cntl++;
        if(a[i]>eq) cntr++;
    }

    if(cntl<=1 || cntr<=1)
    {
        int ans = Diff_Perm(a);
        cout<<ans<<endl;
        return;
    }

    vector<int> b, c;
    int cnt_eq=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]<eq) b.push_back(a[i]);
        else if(a[i]>eq) c.push_back(a[i]);
        else cnt_eq++;
    }

    int ans = Diff_Perm(b)*Diff_Perm(c);
    ans%=mod;
    ans*=2;
    ans%=mod;

    int tn = cnt_eq;
    int tr = n - cnt_eq + 1;
    int tmp = nCr(tn+tr-1, tr-1);
    ans*=tmp;
    ans%=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}