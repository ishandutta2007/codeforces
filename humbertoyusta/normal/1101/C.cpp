/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define ii pair<int,int>
#define iii pair<ii,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

struct nod{
    int l,r,id;
    bool operator < ( const nod & other ) const {
        if( l != other.l ) return l < other.l;
        return r < other.r;
    }
};

int tc,n,have[maxn],g1,g2;
nod a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while(tc--){

        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i].l >> a[i].r;
            a[i].id = i;
        }sort(a+1,a+n+1);

        bool flag = 0, flag2 = 0;
        int g1 = a[1].r, g2 = 0;
        have[a[1].id] = 1;
        for(int i=2; i<=n; i++){
            if( a[i].l <= g1 ){
                if( a[i].l <= g2 )
                    flag2 = 1;
                g1 = max( g1 , a[i].r );
                have[a[i].id] = 1;
            }
            else{
                g2 = max( g2 , a[i].r );
                have[a[i].id] = 2;
                flag = 1;
            }
        }

        if( flag2 || !flag )cout<<-1;
        else for(int i=1; i<=n; i++)
                cout << have[i] << ' ';
        cout << '\n';
    }

    return 0;
}