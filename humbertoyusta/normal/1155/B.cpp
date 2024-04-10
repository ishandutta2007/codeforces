/** Name: Humberto Yusta Gomez
    Pais: Cuba
    Prov: Villa Clara
    Grado: 11no
    Copyright              **/
#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

char m = int( 'a' - 1 );
int ll[maxn],rr[maxn],c8,q8;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    string s;

    int n;cin >> n;

    cin >> s;

    s = '&' + s;

    for(int i=1; i<s.size(); i++){
        c8 += ( s[i] == '8' );
        if( ( (int)s.size() - 1 ) - i + 1 == 11 )
            if( c8 > i / 2 ) cout << "YES";
                else cout << "NO";
    }

    return 0;
}