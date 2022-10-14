#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    long long n,a ,b,q;

    cin >> q;
    while( q-- ){
        cin >> n >> a >> b;
        long long c = 0;
        if( n & 1 ){ n--, c+=a; }
        c += min( a * 2 , b ) * ( n / 2 );
        cout << c << '\n';
    }



    return 0;
}