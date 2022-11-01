#include <bits\stdc++.h>


using namespace std;



int ar[1000][1000];
int j, x, y, n, i;
    void start()
    {
            if ( n == 0 ) {
            printf ( "+\n" );
    exit(0);
    }
    ar[0][0] = 1;
    ar[1][0] = 1;
    ar[0][1] = 1;
    ar[1][1] = 0;
    }

void ans()
{
    for (j=0;j<x;j++){
    for (i=0;i<y;i++)

    if ( ar[j][i] )
     printf ( "+" );
    else printf ( "*" );
    printf ( "\n" );
}
}
int main()
{

//freopen("output.txt","w",stdout);
        scanf ( "%d", &n );
        start();
    x = y = 2;
    for ( int r = 2; r <= n; r++ ) {
            int j, i;
    for (j=0;j<x;j++)
    for (i=y;i<y*2; i++ )
            ar[i][j] = ar[i - y][j];

    for ( j = x; j < 2 * x; j++ )
    for ( i = 0; i < y; i++ )
            ar[i][j] = 1 ^ ( ar[i][2 * x - j - 1] );

    for (j=x;j < 2 * x; j++ )
    for (i=y;i < 2 * y; i++ )
            ar[i][j] = ar[i][2 * x - j - 1];

    x *= 2;
    y *= 2;
    }
    ans();
    return 0;
}