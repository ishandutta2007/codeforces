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

int n, k;
string a, b;

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n >> k;
    cin >> a;

    a = '$' + a;
    b = a;

    for(int i=1; i<=k; i++){
        for(int j=i; j<a.size(); j+=k)
            b[j] = a[i];
    }
    if( a <= b ){
        cout << n << '\n';
        for( int i = 1; i < b.size(); i ++ )
            cout << b[i];
        return 0;
    }

    int nxt = k;
    while( true ){
        if( a[nxt] != '9' ){
            for(int i=nxt; i<a.size(); i+=k)
                b[i] = a[nxt] + 1;
            break;
        }
        else{
            for(int i=nxt; i<a.size(); i+=k)
                b[i] = '0';
            nxt--;
        }
    }

    cout << n << '\n';
    for( int i = 1; i < b.size(); i ++ )
        cout << b[i];

    return 0;
}