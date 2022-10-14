#include<bits/stdc++.h>
#define int long long
#define maxn 100010
#define inf 1000000007
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;

int n, ans(inf), a[maxn], mk[maxn], dist[maxn], p[maxn];
vector<int> c[65], g[maxn], unm;
map<pair<int,int>,bool> mp;
queue<int> q;

int bfs(int nod){
    int res = inf;
    q.push(nod);
    dist[nod] = 1;
    while( !q.empty() ){
        int u = q.front();
        unm.push_back(u);
        q.pop();
        for( auto v : g[u] ){
            if( dist[v] && p[u] != v ){
                res = min( res , dist[u] + dist[v] - 1 + ( v == nod) );
            }
            if( !dist[v] ){
                dist[v] = dist[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
    return res;
}

void unmark(){
    for( auto i : unm )
        dist[i] = p[i] = 0;
    unm.clear();
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        for(int j=0; j<63; j++)
            if( a[i] & ( 1ll << j ) )
                c[j].push_back(i);
    }

    for(int i=0; i<63; i++)
        if( c[i].size() >= 3 ){
            cout << 3;
            return 0;
        }

    for(int i=0; i<63; i++)
        if( c[i].size() == 2 ){
            if( !mp[make_pair(c[i][0],c[i][1])] ){
                g[c[i][0]].push_back(c[i][1]);
                mp[make_pair(c[i][0],c[i][1])] = 1;
            }
            if( !mp[make_pair(c[i][1],c[i][0])] ){
                g[c[i][1]].push_back(c[i][0]);
                mp[make_pair(c[i][1],c[i][0])] = 1;
            }
        }

    for(int i=1; i<=n; i++){
        unmark();
        ans = min( ans , bfs(i) );
    }

    if( ans == inf ) cout << -1;
        else cout << ans;

    return 0;
}