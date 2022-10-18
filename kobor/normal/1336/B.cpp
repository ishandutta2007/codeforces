//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'

const int N=1e5+5;

vi gem[4];
int n[4];

ll sq(int x){
    return 1ll*x*x;
}

ll licz(int a, int b, int c){
    ll ret=4*(1e18);
    for(auto &x: gem[b]){
        int it=upper_bound(gem[a].begin(), gem[a].end(), x)-gem[a].begin();
        if(it != 0) it--;
        int it2=lower_bound(gem[c].begin(), gem[c].end(), x)-gem[c].begin();
        if(it2 == SIZE(gem[c])) it2--;
        ret=min(ret, sq(gem[a][it]-x)+sq(gem[a][it]-gem[c][it2])+sq(gem[c][it2]-x));
    }
    return ret;
}

void solve(){
    int a;
    FOR(i, 1, 3) cin>>n[i];
    FOR(i, 1, 3){
        FOR(j, 1, n[i]){
            cin>>a;
            gem[i].pb(a);
        }
    }
    FOR(i, 1, 3) sort(gem[i].begin(), gem[i].end());
    ll ans=4*(1e18);
    vi vec={1, 2, 3};
    do{
        ans=min(ans, licz(vec[0], vec[1], vec[2]));
    }while(next_permutation(vec.begin(), vec.end()));
    cout<<ans<<ent;
    FOR(i, 1, 3) gem[i].clear();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    FOR(te, 1, tt)
	solve();
	return 0;
}