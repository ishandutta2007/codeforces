#include <cstdlib>
#include <iostream>

using namespace std;

long long N , M , K;

void init ()
{
     cin >> N >> M >> K;
}

void work ()
{
     long long m , t , r;
     m = N % K;
     t = N / K;
     if ( m + t * ( K - 1 ) >= M )
     {
          cout << M % 1000000009 << endl;
     }
     else
     {
         long long ans = 0;
         long long s , tmp , t1;
         r = M - ( m + ( t * ( K - 1 ) ) );
         t1 = r * K;
         s = 1;
         tmp = 2;
         while ( r )
         {
               if ( r % 2 == 1 )
               {
                    s = s * tmp;
                    s = s % 1000000009;
               }
               tmp = tmp * tmp;
               tmp = tmp % 1000000009;
               r = r / 2;
         }
         ans = ( s * 2 - 2 ) * K + M - t1;
         //cout << s << endl;
         cout << ans % 1000000009 << endl;
     }
}

int main(int argc, char *argv[])
{
    init ();
    work ();
    //system("PAUSE");
    return EXIT_SUCCESS;
}