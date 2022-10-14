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

int a, b, c, d, arr[7], mk[1010];

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cout << "? 1 2" << endl;
    cin >> a;

    cout << "? 1 3" << endl;
    cin >> b;

    cout << "? 1 4" << endl;
    cin >> c;

    cout << "? 1 5" << endl;
    cin >> d;

    arr[1] = __gcd( __gcd(a,b) , __gcd(c,d) );
    if( arr[1] != 4 && arr[1] != 8 && arr[1] != 15 && arr[1] != 16 && arr[1] != 23 && arr[1] != 42 )
        arr[1] /= 2;
    mk[arr[1]] = 1;

    arr[2] = a / arr[1];
    mk[arr[2]] = 1;

    arr[3] = b / arr[1];
    mk[arr[3]] = 1;

    arr[4] = c / arr[1];
    mk[arr[4]] = 1;

    arr[5] = d / arr[1];
    mk[arr[5]] = 1;

    if( !mk[4] ) arr[6] = 4;
    if( !mk[8] ) arr[6] = 8;
    if( !mk[15] ) arr[6] = 15;
    if( !mk[16] ) arr[6] = 16;
    if( !mk[23] ) arr[6] = 23;
    if( !mk[42] ) arr[6] = 42;

    cout << "! " << arr[1] << ' ' << arr[2] << ' ' << arr[3] << ' ' << arr[4] << ' ' << arr[5] << ' ' << arr[6] << endl;

    return 0;
}