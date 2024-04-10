#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

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

int main()
{
    string s;
    cin>>s;
    int i = 0;
    while(s[i] != 'e')
        i++;
    int a = s[0]-'0';
    string s1 = s.substr(2,i-2);
    int j = s1.length()-1;
    while(s1[j] == '0'&& j >=0)
        j--;
    s1 = s1.substr(0,j+1);
    int e = stoi(s.substr(i+1,s.length()-(i+1)));
    if(e < s1.length())
    {
        cout<< (s[0]+s1.substr(0,e)+'.'+s1.substr(e,s1.length()-e));
        return 0;
    }
    if(e == s1.length())
    {
        cout<<s[0]+s1;
        return 0;
    }
    string s2 = s[0] + s1;
    for(int i = s1.length()+1;i<=e;i++)
        s2+='0';
    cout<<s2;
}