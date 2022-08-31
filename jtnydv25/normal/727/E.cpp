#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2.5e6;
char A[N];
const ll mod = 1e16+61;
#define sd(n) scanf("%d", &(n))
ll H[N];
map<ll,int> hashes;
const ll B = 109;
ll mulmod(ll a, ll b)
{
    ll x = 0;
    while(b)
    {
        if(b&1) x+=a;
        a+=a;
        b>>=1;
        if(x >= mod) x-= mod;
        if(a >= mod) a -= mod;
    }
    return x;
}
ll powr(ll a, ll b)
{
    ll x = 1;a%=mod;
    while(b){
        if(b&1) x = mulmod(x,a);
        a = mulmod(a,a);
        b>>=1;
    }
    return x; 
}
int main()
{
    int n,k,g;
    sd(n), sd(k);
    scanf(" %s", A);
    string s = (string)A;
    s += s.substr(0,k);
    // cerr<<s<<endl;
    sd(g);
    H[0] = s[0];
    for(int i = 1;i<n*k+k;i++) H[i]=(H[i-1]*B+s[i])%mod;
    for(int i = 0;i<g;i++)
    {
        scanf(" %s", A);
        ll h = 0;
        for(int i = 0;A[i];i++) h = (h*B + A[i])%mod;
        hashes[h] = i+1;    
        // cout<<h<<endl;
    }
    ll BK = powr(B,k);
    // cerr<<BK<<endl;
    for(int i = 0;i<k;i++)
    {
        set<ll> h,done;
        bool f = 1;
        vector<int> vec;
        for(int j = 0;j<n;j++)
        {
            // j*k to (j+1)*k-1.
            ll hs = H[(j+1)*k+i-1] - (j*k+i==0?0:mulmod(BK,H[j*k+i-1]));
            if(hs < 0) hs += mod;
            if(!hashes[hs]||done.find(hs)!=done.end()){f = 0;break;}
            vec.push_back(hashes[hs]);
            done.insert(hs);
        }
        if(f)
        {
            printf("YES\n");
            for(int it: vec) printf("%d ", it);
            return 0;    
        }
    }
    printf("NO");
}