#include <bits/stdc++.h>
#define maxn 500005
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,u,a[maxn];
deque<int> p[7];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    int ans = n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        if( a[i] == 4 ) a[i] = 1;
        if( a[i] == 8 ) a[i] = 2;
        if( a[i] == 15 ) a[i] = 3;
        if( a[i] == 16 ) a[i] = 4;
        if( a[i] == 23 ) a[i] = 5;
        if( a[i] == 42 ) a[i] = 6;
    }

    for(int i=1; i<=n; i++){

        if( a[i] == 1 ){
            p[1].push_back(i);
            continue;
        }

        if( p[a[i]-1].empty() )
            continue;

        p[a[i]-1].pop_front();
        p[a[i]].push_back(i);

        if( a[i] == 6 ) ans -= 6;
    }

    cout << ans << '\n';

    return 0;
}