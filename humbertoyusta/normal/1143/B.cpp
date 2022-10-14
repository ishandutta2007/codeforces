/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

int ans,pot[11];
string n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    pot[0] = 1;
    for(int i=1; i<=10; i++)
        pot[i] = pot[i-1] * 9;

    ans = 1;
    for(int i=0; i<n.size(); i++)
        ans *= ( n[i] - '0' );

    int bef = 1;
    for(int i=0; i<n.size(); i++){
        ans = max( ans , bef * max( int( n[i] -'0' - 1 ) , 1 ) * pot[ (int)n.size() - 1 - i] );
        bef = bef * max( int( n[i] - '0' ) , 1 );
    }

    cout << ans << '\n';

    return 0;
}