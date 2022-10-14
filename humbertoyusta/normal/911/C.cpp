#include <bits/stdc++.h>
#define maxn 10000
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int a[3];
bool mk[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> a[0] >> a[1] >> a[2];

    sort( a , a + 3 );

    do{
        fill(mk,mk+maxn,0);

        for(int i=0; i<maxn; i++)
            if( mk[i] == 0 ){
                int id = i;
                while( id < maxn )
                    mk[id] = 1, id += a[0];
                break;
            }

        for(int i=0; i<maxn; i++)
            if( mk[i] == 0 ){
                int id = i;
                while( id < maxn )
                    mk[id] = 1, id += a[1];
                break;
            }

        for(int i=0; i<maxn; i++)
            if( mk[i] == 0 ){
                int id = i;
                while( id < maxn )
                    mk[id] = 1, id += a[2];
                break;
            }

        bool flag = 1;

        for(int i=0; i<maxn; i++)
            if( mk[i] == 0 ) flag = 0;

        if( flag ){
            cout << "YES";
            return 0;
        }

    }while( next_permutation( a , a + 3 ) );

    cout << "NO";

    return 0;
}