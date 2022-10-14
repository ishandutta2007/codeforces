#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define maxn 200010
#define inf 100000000000000007ll
using namespace std;

int n, a[maxn], c[maxn], st[4*maxn], lazy[4*maxn];

void lazyp(int nod,int l,int r){
    st[nod] += lazy[nod];
    if( l != r ){
        lazy[2*nod] += lazy[nod];
        lazy[2*nod+1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void update(int nod,int l,int r,int x,int y,int val){
    if( l > r ) return;
    lazyp(nod,l,r);
    if( l > y || r < x ) return;
    if( l >= x && r <= y ){
        lazy[nod] += val;
        lazyp(nod,l,r);
        return;
    }
    int mi = ( l + r ) >> 1;
        update(2*nod,l,mi,x,y,val);
        update(2*nod+1,mi+1,r,x,y,val);
    st[nod] = min( st[2*nod] , st[2*nod+1] );
}

int query(int nod,int l,int r,int x,int y){
    lazyp(nod,l,r);
    if( l > y || r < x ) return inf;
    if( l >= x && r <= y ) return st[nod];
    int mi = ( l + r ) >> 1;
    return min( query(2*nod,l,mi,x,y) , query(2*nod+1,mi+1,r,x,y) );
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        cin >> c[i];

    for(int i=1; i<=n; i++)
        update(1,1,n,a[i]+1,n,c[i]);

    int ans = inf;
    for(int i=1; i<n; i++){
        update(1,1,n,a[i]+1,n,-c[i]);
        update(1,1,n,1,a[i]-1,c[i]);
        ans = min( ans , query(1,1,n,1,n) );
    }
    cout << ans << '\n';

    return 0;
}