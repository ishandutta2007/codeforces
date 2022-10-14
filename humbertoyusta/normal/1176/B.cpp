#include <bits/stdc++.h>
#define maxn 110
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
ll n,a[maxn],sum,c[3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> q;

    while( q-- ){

        cin >> n;
        sum = 0;
        c[0] = c[1] = c[2] = 0;

        for(int i=1; i<=n; i++){
            cin >> a[i];
            a[i] %= 3;
            c[a[i]]++;
        }

        ll tmp = min( c[1] , c[2] );
        c[1] -= tmp; c[2] -= tmp;

        cout << c[0] + tmp + c[1] / 3ll + c[2] / 3ll << '\n';
    }


    return 0;
}