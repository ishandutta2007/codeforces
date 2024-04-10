#include<bits/stdc++.h>
#define maxn 110
using namespace std;

int tc,n,k,a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    while( tc-- ){

        cin >> n >> k;

        for(int i=1; i<=n; i++)
            cin >> a[i];

        sort( a + 1 , a + n + 1 );

        int ch = a[1] + k;

        bool flag = 1;
        for(int i=1; i<=n; i++)
            if( abs( ch - a[i] ) > k )
                flag = 0;

        if( flag ){ cout << ch << '\n'; }
            else{ cout << -1 << '\n'; }
    }

    return 0;
}