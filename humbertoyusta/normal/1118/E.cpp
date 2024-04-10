#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,k;
vector<ii> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> k;

    int fi = 1, se = 2;
    while( v.size() < n ){
        if( fi >= k ){
            cout << "NO\n";
            return 0;
        }
        v.push_back({fi,se});
        if( v.size() < n) v.push_back({se,fi});
        se++;
        if( se > k ){
            fi++;
            se = fi + 1;
        }
    }

    cout << "YES\n";

    for( auto i : v )
        cout << i.f << ' ' << i.s << '\n';

    return 0;
}