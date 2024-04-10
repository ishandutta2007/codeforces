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

int n,ans;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=lg2(n); i>=0; i--){
        if( !( n & (1<<i) ) ){
             ans += 2;
             v.push_back(i+1);
             n ^= (1<<(i+1)) - 1;
             if( __builtin_popcount(n) == lg2(n) + 1 ){ ans--; break;}
             n++;
        }
    }

    cout << ans << '\n';
    for( auto i : v )
        cout << i << ' ';

    return 0;
}