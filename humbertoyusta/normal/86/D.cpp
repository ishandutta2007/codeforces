#include<bits/stdc++.h>
#define maxn 200005
#define maxN 1000010
using namespace std;

int n,sq;
struct query{
    int l,r,id;
    bool operator < ( const query & other ) const {
        if( l / sq != other.l / sq ) return l < other.l;
        return r < other.r;
    }
}q[maxn];
int m,a[maxn],c[maxN];
long long res[maxn],ans;

void add_(int x){
    ans += ( 2 * c[a[x]] + 1 ) * a[x];
    c[a[x]]++;
}

void remove_(int x){
    c[a[x]]--;
    ans -= ( 2 * c[a[x]] + 1 ) * a[x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    cin >> n >> m;
    sq = int(sqrt(n));

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=m; i++){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    stable_sort(q+1,q+m+1);

    int L = q[1].l , R = L - 1;

    for(int i=1; i<=m; i++){
        while( L > q[i].l )
            add_(--L);
        while( L < q[i].l )
            remove_(L++);
        while( R < q[i].r )
            add_(++R);
        while( R > q[i].r)
            remove_(R--);
        res[q[i].id] = ans;
    }

    for(int i=1; i<=m; i++)
        cout << res[i] << '\n';

    return 0;
}