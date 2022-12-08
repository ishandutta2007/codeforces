#include <cstdlib>
#include <iostream>

using namespace std;

struct player
{
    int l;
    int a[300];
    bool f;
} p[200];

int n;

void init ()
{
     int i , j , t;
     cin >> n;
     for ( i = 1 ; i <= n ; i++ )
     {
         cin >> p[i].l;
         p[i].f = true;
         for ( j = 1 ; j <= p[i].l ; j++ )
         {
             cin >> t;
             p[i].a[t] = 1;
         }
     }
}

void work ()
{
     int i , j , k;
     bool flag;
     for ( i = 1 ; i <= n ; i++ )
     {
         for ( j = 1 ; j <= n ; j++ )
         {
             if ( j != i )
             {
                  flag = false;
                  for ( k = 1 ; k <= 100 ; k++ )
                  {
                      if ( p[i].a[k] == 0 && p[j].a[k] == 1 )
                      {
                           flag = true;
                           break;
                      }
                  }
                  if ( flag == false )
                  {
                       p[i].f = false;
                       break;
                  }
             }
             //cout << i << " " << j << p[i].f << endl;
         }
     }
     for ( i = 1 ; i <= n ; i++ )
     {
         if ( p[i].f == true )
         {
              cout << "YES" << endl;
         }
         else
         {
             cout << "NO" << endl;
         }
     }
}

int main(int argc, char *argv[])
{
    init ();
    work ();
    //system("PAUSE");
    return EXIT_SUCCESS;
}