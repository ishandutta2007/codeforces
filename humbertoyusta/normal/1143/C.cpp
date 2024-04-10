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

int n,p[maxn],r[maxn];
vector<int> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> p[i] >> r[i];
        if( p[i] != -1 )
            g[p[i]].push_back(i);
    }

    bool flag = 0;
    for(int i=1; i<=n; i++){
        bool b = 0;
        for(auto j : g[i])
            if( !r[j] )
                b = 1;
        if( b == 0 && r[i] ){
            cout << i << ' ';
            flag = 1;
        }
    }

    if(!flag) cout << -1;

    return 0;
}