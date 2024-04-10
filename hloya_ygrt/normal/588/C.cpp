#include <stdio.h>

using namespace std;

    long long w[2000000];
int main()
{
    int n, a, i, ans=0;
    scanf ( "%d", &n );

    for (i=0;i<2000000;i++)
        w[i]=0;

    for ( i = 0; i < n; i++ )
    {
        scanf ( "%d", &a );
        w[a]++;
    }

    for ( i = 0; i < 2000000; i++ )
    {
        if (w[i]!=0){
        w[i+1]+=w[i]/2;
        w[i]%=2;
        }
    }
    for ( i = 0; i < 2000000; i++ )
        ans += w[i];
    printf ( "%d",ans);

    return 0;
}