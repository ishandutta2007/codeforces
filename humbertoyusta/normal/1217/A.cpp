#include<bits/stdc++.h>
#define maxn 100010
#define ii pair<int,int>
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int a, b, c, d;
        cin >> a >> b >> c;
        d = a + c;
        cout << max( 0 , min( c , ( d - b - 1 ) / 2 ) + ( d > b ) ) << '\n';
    }

    return 0;
}