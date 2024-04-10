#include<bits/stdc++.h>
#define maxn 1010
#define f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double Ld;
typedef pair<int,int> ii;

int n, m, a[maxn], tand[maxn], tad[maxn];
pair<int,ii> q[maxn];

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        q[i] = {u,{v,w}};
        if( u == 1 ){
            tand[v+1]++;
            tand[w+1]--;
        }
        if( u == 0 ){
            tad[v+1]++;
            tad[w+1]--;
        }
    }

    for(int i=1; i<=n; i++){
        tand[i] += tand[i-1];
        tad[i] += tad[i-1];
    }

    a[1] = n;

    for(int i=2; i<=n; i++){
        if( tand[i] ) a[i] = a[i-1];
            else a[i] = a[i-1] - 1;
    }

    bool can = 1;
    for(int i=1; i<=m; i++){
        if( q[i].f == 1 ){
            if( a[q[i].s.f] < a[q[i].s.s] ){
                can = 0;
            }
        }
        else{
            if( a[q[i].s.f] <= a[q[i].s.s] ){
                can = 0;
            }
        }
    }

    if( !can ){ cout << "NO\n"; return 0; }

    cout << "YES\n";

    for(int i=1; i<=n; i++)
        cout << a[i] << '\n';

    return 0;
}