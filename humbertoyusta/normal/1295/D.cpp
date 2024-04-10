#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define maxn 1010
#define mod 1000000007
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    int tc, n, x;
    string s;
    cin >> tc;
    while( tc-- ){
        cin >> x >> n;
        n = n / __gcd( x , n );
        int phi = n;
        for(int i=2; i*i<=n; i++){
            if( n % i == 0 ){
                phi -= phi / i;
                while( n % i == 0 )
                    n /= i;
            }
        }
        if( n != 1 )
            phi -= phi / n;
        cout << phi << '\n';
    }

    return 0;
}