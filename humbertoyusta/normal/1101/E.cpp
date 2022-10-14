/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a,b,ma,mb;
char op;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    while(n--){
        cin >> op >> a >> b;
        if( op == '+' ){
            if( b < a ) swap(a,b);
            ma = max( ma , a );
            mb = max( mb , b );
        }
        if( op == '?' ){
            if( b < a ) swap( a , b );
            if ( a >= ma && b >= mb ) cout << "YES\n";
                else cout << "NO\n";
        }
    }

    return 0;
}