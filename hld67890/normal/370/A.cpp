#include <cstdlib>
#include <iostream>

using namespace std;

int x1 , x2 , y1 , y2;

void init ()
{
     cin >> x1 >> y1 >> x2 >> y2;
}

int abss ( int a )
{
    if ( a < 0 )
    {
         return -a;
    }
    else
    {
        return a;
    }
}

void work ()
{
     if ( x1 == x2 && y1 == y2 )
     {
          cout << "0 0 0" << endl;
     }
     cout << ( abss ( x1 - x2 ) && 1 ) + ( abss ( y1 - y2 ) && 1 ) << " ";
     if ( ( x1 + y1 ) % 2 != ( x2 + y2 ) % 2 )
     {
          cout << "0 ";
     }
     else
     {
         if ( x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2 )
         {
              cout << "1 ";
         }
         else
         {
             cout << "2 ";
         }
     }
     if ( abss ( x1 - x2 ) < abss ( y1 - y2 ) )
     {
          cout << abss ( y1 - y2 ) << endl;
     }
     else
     {
         cout << abss ( x1 - x2 ) << endl;
     }
}

int main(int argc, char *argv[])
{
    init ();
    work ();
    //system("PAUSE");
    return EXIT_SUCCESS;
}