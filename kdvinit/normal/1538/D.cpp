/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define $Prime_Length 40000     //Max length here is 519160
bool Is_It_Prime[$Prime_Length];
vector<int> Primes;

/**Note that 0 and 1 or not prime here **/
int Make_Prime()
{
    for(int i=2;i<$Prime_Length;i++) Is_It_Prime[i]=1;
    for(int i=2;i*i<$Prime_Length;i++) { if(Is_It_Prime[i]==1) for(int j=i*i;j<$Prime_Length;j+=i) Is_It_Prime[j]=0; }

    for(int i=2;i<$Prime_Length;i++) if(Is_It_Prime[i]) Primes.push_back(i);

    return 0;
}
int Implement_Make_Prime=Make_Prime();


int GCD(int x, int y)
{
   if(y==0) return x;
   else return GCD(y, x%y);
}

int find_min(int x, int y)
{
    if(x==y) return 0;
    if(x%y==0) return 1;
    return 2;
}

int num_factors(int z)
{
    int cnt=0;

    for(auto x: Primes)
    {
        if(z==1) break;
        if(x*x>z) break;

        while(z%x==0) { z/=x; cnt++; }
    }
    if(z!=1) cnt++;
    return cnt;
}

void solve()
{
    int a, b, k;
    cin>>a>>b>>k;

    int x = max(a, b), y = min(a, b);

    int mn = find_min(x, y);

    if(k==1)
    {
        if(x%y==0 && x!=y) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }

    if(k<mn) { cout<<"NO"<<endl; return; }


    int nx = num_factors(x);
    int ny = num_factors(y);

    int mx = nx+ny;

    if(k>(nx+ny)) { cout<<"NO"<<endl; return; }

    int par=0;
    if(nx>1 || ny>1) par=1;
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}