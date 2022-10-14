#include<bits/stdc++.h>
#define maxn 2000010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

int abi[maxn],n,k,a[maxn],p[maxn],l[maxn],r[maxn],st[maxn*4],lazy[maxn*4],cont;
vector<int> g[maxn];

void update(int id,int val){
    for(; id > 0; id -= ( id & -id))
        abi[id] = min( abi[id] , val );
}

int query(int id){
    int res = n+1;
    for(; id <= n; id += ( id & -id ))
        res = min( res , abi[id] );
    return res;
}

void dfs(int u){
    l[u] = r[u] = cont++;
    for(auto v : g[u])
        dfs(v);
    for(auto v : g[u])
        r[u] = max( r[u] , max( l[v] , r[v] ) );
}

void lazyp(int nod,int l,int r){
    st[nod] += lazy[nod];
    if( l != r ){
        lazy[2*nod] += lazy[nod];
        lazy[2*nod+1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void update(int nod,int l,int r,int x,int y,int val){

    if( l > y || r < x ) return;
    if( lazy[nod] != 0 ) lazyp(nod,l,r);
    if( l >= x && r <= y ){
        lazy[nod] = val;
        lazyp(nod,l,r);
        return;
    }

    int mi = ( l + r ) / 2;
        update(2*nod,l,mi,x,y,val);
        update(2*nod+1,mi+1,r,x,y,val);

    lazyp(2*nod,l,mi);
    lazyp(2*nod+1,mi+1,r);

    st[nod] = max( st[2*nod] , st[2*nod+1] );
}

int query(int nod,int l,int r,int x,int y){

    if( l > y || r < x ) return 0;
    if( lazy[nod] != 0 ) lazyp(nod,l,r);
    if( l >= x && r <= y ) return st[nod];

    int mi = ( l + r ) / 2;
        int aa = query(2*nod,l,mi,x,y);
        int bb = query(2*nod+1,mi+1,r,x,y);

    return max( aa , bb );
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    a[n+1] = n+1;
    fill(abi,abi+n+2,n+1);

    for(int i=n; i>=1; i--){
        update(a[i],i);
        p[i] = query(a[i]+1);
        g[p[i]].push_back(i);
    }

    dfs(n+1);

    int ans = 0;
    for(int i=1; i<=n; i++){
        update(1,1,n,l[i],r[i],1);
        if( i-k >= 1 ) update(1,1,n,l[i-k],r[i-k],-1);
        if( i-k >= 0 ) cout << query(1,1,n,1,n) << ' ';
    }

    return 0;
}