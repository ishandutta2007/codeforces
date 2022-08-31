#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

void gett()
{
    cerr<< (clock())/(double)cps<<endl;
}

ll powr(ll a, ll b, ll mod)
{
    ll x = 1%mod;
    a %= mod;
    while(b)
    {
        if(b&1)
            x = (x*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return x;
}
ll inv(ll a, ll mod)
{
    return powr(a,mod-2,mod);
}

const int maxn = 1e6+10;
const ll mod = 1e9+7;
string a[40],b[40];
map<string,int> st[6];
void dfs(int k,int n,int q)
{
    for(auto j:st[k])
    {
        string s = j.F;
        for(int i = 0;i<q;i++)
            if(s.substr(0,2) == a[i]){
                string s1 = b[i]+s.substr(2,s.length()-2);
                st[k+1][s1] += st[k][s]; 
            }
    }
}
int n,q;
void dfs1(string s,int l)
{
    if(l == n)
    {
        st[0][s]++;
        return;
    }
    for(int i = 0;i<6;i++)
    {
        string s1 = s+(char)((int)('a')+i);
        dfs1(s1,l+1);
    }
}
int main()
{
    
    sd(n),sd(q);
    string s = "";
    dfs1(s,0);
   
    rep(i,0,q)
    {
        cin>>a[i]>>b[i];
    }
    for(int i = 0;i<n-1;i++){
        dfs(i,n,q);
    }
    cout<<st[n-1]["a"];

}