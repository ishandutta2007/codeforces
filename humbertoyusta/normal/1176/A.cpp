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

int q;
ll n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> q;

    while( q-- ){
        cin >> n;
        int c = 0;

        while( n % 5 == 0 ){
            c++;
            n *= 4;
            n /= 5;
        }

        while( n % 3 == 0 ){
            c++;
            n *= 2;
            n /= 3;
        }

        while( n % 2 == 0 ){
            c++;
            n /= 2;
        }


        if( n != 1 ) cout << -1 << '\n';
            else cout << c << '\n';
    }


    return 0;
}