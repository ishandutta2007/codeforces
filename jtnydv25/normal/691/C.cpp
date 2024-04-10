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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))

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

int main()
{
    string s;
    cin>>s;
    int i =0 ;
    string ret = "";
    while(s[i] == '0' && i <s.length() )
        i++;
    if(i==s.length())
    {
        cout<<0;
        return 0;
    }
    if(s[i] == '.')
    {
        int cnt = 0;
        i++;
        while(s[i] == '0')
        {
            cnt++;
            i++;
        }

        ret+=s[i];
        i++;
        if(i==s.length())
        {
            ret+='E'+to_string(-cnt-1);
            cout<<ret;
            return 0;
        }
        ret+='.';
        ret += s.substr(i,s.length()-i);
        i = ret.length()-1;
        while(ret[i]=='0')
            i--;
        if(ret[i]=='.')
            i--;
        ret = ret.substr(0,i+1);
        ret+='E'+to_string(-cnt-1);
        cout<<ret;
        return 0;
    }
    ret += s[i];
    int cnt = 0;
    i++;
    int j = i;
    
    if(i==s.length())
    {
        cout<<ret;
        return 0;
    }
    while(s[i] != '.'&& i!=s.length())
    {
        cnt ++;
        i++;
    }
    ret+='.';
    ret += s.substr(j,i-j);
    if(i!=s.length())
    i++;
    ret+=s.substr(i,s.length()-i);
    i = ret.length()-1;
    while(ret[i]=='0')
        i--;
    if(ret[i]=='.')
            i--;    
    ret = ret.substr(0,i+1);   
    if(cnt!=0)
        ret+='E'+to_string(cnt);

    cout<<ret;
}