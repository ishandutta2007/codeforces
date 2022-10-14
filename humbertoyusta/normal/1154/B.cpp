#include<bits/stdc++.h>
#define maxn 110
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[maxn],b[maxn],c;
set<int> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w".stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }

    for(auto i : s)
        b[c++] = i;

    if( c == 1 ){ cout << 0; return 0; }

    if( c == 2 ){ if( (b[1]-b[0])%2==0 ) cout << ( b[1] - b[0] ) / 2; else cout << b[1] - b[0]; return 0; }

    if( c == 3 && b[2] - b[1] == b[1] - b[0] ){ cout << b[1] - b[0]; return 0; }

    cout << -1;

    return 0;
}