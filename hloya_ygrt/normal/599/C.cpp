#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <math.h>



using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;

int i[maxn];

    pair < int, int > tree[4 * maxn];

    int oper ( int a, int b ) {
    //if (a==b)
    //    return a-1;
    //else
    return min (a,b);
                            }

void build ( int v, int l, int r ) {
        if ( l == r ) {
            tree[v] = mp ( i[l], l );
            return ;
                        }
        int mid = ( l + r ) >> 1;
        int new_v = v << 1;
        build ( new_v, l, mid );
        build ( new_v + 1, mid + 1, r );

        if ( tree[new_v].f >= tree[new_v + 1].f ) {
            tree[v] = mp ( tree[new_v + 1].f, tree[new_v + 1].s );
                                                  }
        else
            tree[v] = mp ( tree[new_v].f, tree[new_v].s );
}

pair < int, int > find_min ( int v, int tree_l, int tree_r, int l, int r ) {

    if ( l > r ) return mp( inf, inf );

        if ( tree_l == l && tree_r == r ) return mp( tree[v].f, tree[v].s );

            int mid = ( tree_l + tree_r ) >> 1;
                int new_v = v << 1;

            pair < int, int > f1 = find_min ( new_v, tree_l, mid, l, min( r, mid ) );
            pair < int, int > f2 = find_min ( new_v + 1, mid + 1, tree_r, max( l, mid + 1 ), r );

            if ( f1.f < f2.f ) {
                return f1;
}
else return f2;
}

int main()
{
    int n,k,j,r=1,ans = 1,l=1;
    scanf( "%d", &n);

    for (k=1;k<=n;k++)
    scanf ("%d",&i[k]);
    int tmin=i[1],tmax=i[1];
    build( 1, 1, n );

    while ( r != n ) {

            pair < int, int > t = find_min( 1, 1, n, r + 1, n );

            int minost=t.f;
            if (tmax<=minost)
            {
                ans++;

                r++;
                tmax=i[r];
                l=r;
            }
            else
            {
                tmax=max(i[r],tmax);
                r++;
            }

                    }
        printf ( "%d", ans );
return 0;
}