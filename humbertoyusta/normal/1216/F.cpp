#include<bits/stdc++.h>
#define int long long
#define maxn 400005
#define inf 1000000000000000007ll
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int n, k, dp[maxn], st[4*maxn];
string s;

void update(int nod,int l,int r,int id,int val){

    if( l == r ){ st[nod] = val; return; }

    int mi = ( l + r ) >> 1;
    if( id <= mi ) update(2*nod,l,mi,id,val);
        else update(2*nod+1,mi+1,r,id,val);

    st[nod] = min( st[2*nod] , st[2*nod+1] );
}

int query(int nod,int l,int r,int x,int y){

    if( l > y || r < x ) return inf;

    if( l >= x && r <= y ) return st[nod];

    int mi = ( l + r ) >> 1;
        int aa = query(2*nod,l,mi,x,y);
        int bb = query(2*nod+1,mi+1,r,x,y);

    return min( aa , bb );
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    cin >> s;
    s = '$' + s;

    for(int i=1; i<=n; i++)
        dp[i] = inf;
    dp[0] = 0;

    fill( st , st + 4 * maxn , inf );

    update(1,0,n+k,0,0);
    int ans = inf;
    for(int i=1; i<=n+k; i++){
        dp[i] = dp[i-1] + i;
        if( s[max(0ll,i-k)] == '1' ){
            dp[i] = min( dp[i] , query( 1 , 0 , n + k , i - k - k - 1 , i - 1 ) + i - k );
        }
        if( i >= n ) ans = min( ans , dp[i] );
        update( 1 , 0 , n + k , i , dp[i] );
    }

    cout << ans << '\n';

    return 0;
}