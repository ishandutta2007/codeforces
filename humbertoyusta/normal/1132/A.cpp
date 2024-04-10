#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r".stdin);
    //freopen("a.out","w".stdout);

    int c1,c2,c3,c4;
    cin >> c1 >> c2 >> c3 >> c4;

    if( c1 != c4 ){ cout << 0; return 0; }

    if( !c1 && c3 ){ cout << 0; return 0; }

    cout << 1;

    return 0;
}