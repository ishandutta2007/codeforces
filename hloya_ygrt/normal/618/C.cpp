#include<bits/stdc++.h>


using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long
//#define ll long long
#define mp make_pair
#define int long long
const int maxn = 1e5 + 300, inf = 2e9;


pair < pair < int, int >, int > a[maxn];
int n;
   
bool can( int j, int i, int y ) {
    if ( j == y || i == y ) return 0;

    int deltaX = a[y].f.f - a[j].f.f;
    if ( !deltaX ) return 1;
    int q = __gcd( a[i].f.f - a[j].f.f, abs( a[i].f.s - a[j].f.s ) );
    if ( deltaX % ( ( a[i].f.f - a[j].f.f ) / q ) ) return 1;
    ll deltaY = 1LL * ( ( a[i].f.s - a[j].f.s ) / q ) * ( deltaX / ( ( a[i].f.f - a[j].f.f ) / q ) );
    if ( 1LL * a[j].f.s + deltaY == 1LL * a[y].f.s ) return 0;
    return 1;
}


    int _try(int left,int right){
        int m = 0;
        while ( m < n ) {
        if ( can( left, right, m ) ) {
                //pt3 = a[m].s;
                return a[m].s;
        }
            m++;
        }
    }
main()
{
    int j;
    scanf ( "%I64d", &n );
    for (int j = 0; j < n; j++ )
        {
            a[j].s=j+1;
            scanf ("%I64d %I64d",&a[j].f.f,&a[j].f.s );
        }
    sort(a,a+n);
    int pt1,pt2,pt3;
    int left = 0;
    int i = 0;
    pt1 = a[0].s;

    while (a[i + 1].f.f == a[i].f.f)
        i++;

    j=i;
    pt2 = a[j+1].s;
    int right = j+1;
    pt3 = _try(left,right);
    printf("%I64d %I64d %I64d",pt1,pt2,pt3);
    return 0;
}