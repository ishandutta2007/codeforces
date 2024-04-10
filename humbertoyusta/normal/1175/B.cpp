#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;

ll n,c[maxn],curr[maxn],prof;
string s[maxn];
stack<ll> p;
vector<ll> ad;
vector< pair<ii,ii> > v;
ii st[maxn];

ll dfs(int id){

    ll val = v[id].s.s;

    for(int i=v[id].f.f+1; i<v[id].f.s; ){

        if( st[i].f == 0 ){ i++; continue; }

        val += dfs( st[i].s );

        if( val >= (1ll<<32) )
            val = (1ll<<32);

        i = st[i].f + 1;
    }

    val *= v[id].s.f;

    if( val >= (1ll<<32) )
        val = (1ll<<32);

    return val;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;
    v.push_back({{0,n+1},{1,0}});

    for(int i=1; i<=n; i++){
        cin >> s[i];
        if( s[i] == "for" ){
            p.push(i);
            cin >> c[i];
            prof++;
        }
        if( s[i] == "add" ){
            curr[prof] ++;
        }
        if( s[i] == "end" ){
            v.push_back({{p.top(),i},{c[p.top()],curr[prof]}});
            p.pop();
            curr[prof] = 0;
            prof--;
        }
    }

    v[0].s.s = curr[0];

    stable_sort( v.begin() , v.end() );

    for(int i=0; i<v.size(); i++)
        st[v[i].f.f] = {v[i].f.s,i};

    ll ans = dfs(0);
    if( ans >= (1ll<<32) ) cout << "OVERFLOW!!!";
        else cout << ans;

    return 0;
}