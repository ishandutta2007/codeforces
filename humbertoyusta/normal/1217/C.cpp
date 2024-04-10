#include<bits/stdc++.h>
#define maxn 200010
#define ii pair<int,int>
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

char s[maxn];
int ans, z[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while( tc-- ){

        cin >> ( s + 1 );
        int n = strlen( s + 1 );
        fill( z , z + n + 1 , 0 );

        for(int i=1; i<=n; i++)
            if( s[i] == '0' ) z[i] = z[i-1] + 1;
                else z[i] = 0;

        int ans = 0;

        for(int i=1; i<=n; i++){
          if( s[i] == '1' )
            for(int j=1; j<20; j++){
                if( i + j - 1 > n ) break;
                int num = 0;
                for(int k=i+j-1; k>=i; k--){
                    if( s[k] == '1' )
                        num += ( 1 << ( i + j - 1 - k ) );
                }
                if( num <= z[i-1] + j ) ans ++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}