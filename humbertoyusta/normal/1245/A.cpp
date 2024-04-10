#include<bits/stdc++.h>
#define inf 1000000007
#define maxn 100010
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
typedef long long ll;

int n, a, b;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a >> b;
        if( a < b ) swap( a , b );
        if( __gcd( a , b ) == 1 ) cout << "Finite\n";
            else cout << "Infinite\n";
    }

    return 0;
}