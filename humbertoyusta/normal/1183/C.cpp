#include<bits/stdc++.h>
#define maxn 200005
using namespace std;

long long tc, n, m, a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    while( tc-- ){

        cin >> n >> m >> a >> b;
        n--;

        if( n - m * b < 0 ){
            cout << -1 << '\n';
            continue;
        }

        cout << min( m , max( 0ll , ( n - m * b ) / ( a - b ) ) ) << '\n';
    }

    return 0;
}