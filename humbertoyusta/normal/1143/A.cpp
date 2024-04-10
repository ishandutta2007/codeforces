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

int n,z[maxn],o[maxn];
bool a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        z[i] = z[i-1] + ( a[i] == 0 );
        o[i] = o[i-1] + ( a[i] == 1 );
    }

    for(int i=1; i<=n; i++){
        if( z[i] == z[n] ){ cout << i; return 0; }
        if( o[i] == o[n] ){ cout << i; return 0; }
    }

    return 0;
}