/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
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

int q,l,r,d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> q;

    while(q--){
        cin >> l >> r >> d;
        if( d < l || d > r ){ cout << d << '\n'; continue; }
        if( l - ( l % d ) < l && l - ( l % d ) > 0 ){ cout << l - ( l % d ) << '\n'; continue; }
        if( r + ( d - r % d ) > r ){ cout << r + ( d - r % d ) << '\n'; continue;  }
        cout << r + d + ( d - r % d ) << '\n';
    }

    return 0;
}