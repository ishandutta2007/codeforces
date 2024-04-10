#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 2002
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int n, c[maxn], x[maxn], y[maxn], e[maxn], p[maxn], ans;
vector<pair<int,ii>> v;
vector<int> ans1;
vector<ii> ans2;

int cost(int i,int j){
    return ( e[i] + e[j] ) * ( abs( x[i] - x[j] ) + abs( y[i] - y[j] ) );
}

int find_(int nod){
    if( p[nod] == nod ) return nod;
    return p[nod] = find_( p[nod] );
}

void kruskall(){
    for( auto i : v ){
        int u = i.s.f;
        int v = i.s.s;
        int w = i.f;

        if( find_(u) == find_(v) ) continue;

        p[find_(v)] = find_(u);
        ans += w;
        if( u == 0 ) ans1.push_back(v);
            else ans2.push_back({u,v});
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> x[i] >> y[i];

    for(int i=1; i<=n; i++){
        cin >> c[i];
        v.push_back({c[i],{0,i}});
    }

    for(int i=1; i<=n; i++)
        cin >> e[i];

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            v.push_back({cost(i,j),{i,j}});

    sort(v.begin(),v.end());

    for(int i=1; i<=n; i++)
        p[i] = i;

    kruskall();

    cout << ans << '\n';

    cout << ans1.size() << '\n';

    for( auto i : ans1 )
        cout << i << ' ';

    cout << '\n';

    cout << ans2.size() << '\n';

    for( auto i : ans2 )
        cout << i.f << ' ' << i.s << '\n';

    return 0;
}