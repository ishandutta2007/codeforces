#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

ll w,c[9],ans;
vector<ll> v;

void call(ll id,ll sum){
    if( sum > w ) return;
    ans = max( ans , sum );
    if( id == 8 ) return;
    ll cant = min( ( w - sum ) / v[id] , c[v[id]] );
    if( cant >= 0 ) call( id+1 , sum + cant * v[id] );
    if( cant >= 1 ) call( id+1 , sum + (cant-1) * v[id] );
    //if( cant >= 2 ) call( id+1 , sum + (cant-2) * v[id] );
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> w;

    for(int i=1; i<=8; i++)
        cin >> c[i];

    for(ll i=1; i<=8; i++)
        v.push_back(i);

    ans = 0;
    while(next_permutation(v.begin(),v.end()))
        call(0,0);

    cout << ans << '\n';

    return 0;
}