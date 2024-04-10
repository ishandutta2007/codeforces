#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

string a, b, c;
int n, n1, n2;

int print(string s){
    cout << s << endl;
    int w;
    cin >> w;
    if( w == 0 )
        exit(0);
    return w;
}

int32_t main(){
    //ios_base::sync_with_stdio(0);  cin.tie(0);
    //cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    for(int i=1; i<=300; i++){
        a += 'a';
        b += 'b';
    }

    n1 = print(a);
    n2 = print(b);

    n = ( 300 - n1 ) + ( 300 - n2 );

    if( n1 == 300 ){
        for(int i=1; i<=n; i++)
            c += 'b';
        print(c);
    }
    if( n2 == 300 ){
        for(int i=1; i<=n; i++)
            c += 'a';
        print(c);
    }

    for(int i=1; i<=n; i++)
        c += 'a';

    int res[303];
    res[0] = n - ( 300 - n1 );
    for(int i=1; i<=n; i++){
        c[i-1] = 'b';
        res[i] = print(c);
        if( res[i] < res[i-1] ) ;
            else c[i-1] = 'a';
    }

    return 0;
}