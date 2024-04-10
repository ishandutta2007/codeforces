#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int N = 1e5+10;

int main()
{
    cin.tie(0);
    string s;
    cin>>s;
    int l = s.length();
    if(l&1)
    {
        cout<<-1;
        return 0;
    }
    int x = 0,y = 0;
    rep(i,0,l)
    {
        if(s[i]=='L')
            x--;
        if(s[i]=='R')
            x++;
        if(s[i]=='U')
            y++;
        if(s[i]=='D')
            y--;
    }
    cout<<((abs(x)+abs(y))/2);
}