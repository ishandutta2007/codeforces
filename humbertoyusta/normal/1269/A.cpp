#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    int n;
    cin >> n;

    if( n % 2 == 0 ){
        cout << n + 4 << ' ' << 4 << '\n';
        return 0;
    }
    else{
        cout << n + 9 << ' ' << 9 << '\n';
        return 0;
    }

    return 0;
}