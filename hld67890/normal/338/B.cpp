#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct node
{
       int e;
       node *next;
} pool[200000] , *g[200000];

int N , M , D;
int top;
bool f[200000];
int m[200000] , max1[200000] , max2[200000] , from1[200000];
int ans;

void init ()
{
     int i , t , a , b;
     cin >> N >> M >> D;
     for ( i = 1 ; i <= M ; i++ )
     {
         cin >> t;
         f[t] = 1;
     }
     for ( i = 1 ; i <= N - 1 ; i++ )
     {
         cin >> a >> b;
         node *tmp1 = &pool[top++];
         node *tmp2 = &pool[top++];
         tmp1 -> e = b;
         tmp1 -> next = g[a];
         g[a] = tmp1;
         tmp2 -> e = a;
         tmp2 -> next = g[b];
         g[b] = tmp2;
     }
}

void dfs1 ( int t , int from )
{
     m[t] = max1[t] = max2[t] = -999999;
     if ( f[t] == true )
     {
          m[t] = 0;
     }
     for ( node *j = g[t] ; j ; j = j -> next )
     {
         if ( j -> e == from )
         {
              continue;
         }
         dfs1 ( j -> e , t );
         m[t] = max ( m[t] , m[j -> e] + 1 );
         if ( m[j -> e] + 1 > max1[t] )
         {
              max2[t] = max1[t];
              max1[t] = m[j -> e] + 1;
              from1[t] = j -> e;
         }
         else
         {
             if ( m[j -> e] + 1 > max2[t] )
             {
                  max2[t] = m[j -> e] + 1;
             }
         }
     }
}

void dfs2 ( int t , int from , int dis )
{
     int ndis;
     if ( max ( dis , m[t] ) <= D )
     {
          ans++;
     }
     for ( node *j = g[t] ; j ; j = j -> next )
     {
         if ( j -> e == from )
         {
              continue;
         }
         ndis = dis + 1;
         if ( j -> e == from1[t] )
         {
              ndis = max ( ndis , max2[t] + 1 );
         }
         else
         {
             ndis = max ( ndis , max1[t] + 1 );
         }
         if ( f[t] == 1 )
         {
              ndis = max ( ndis , 1 );
         }
         dfs2 ( j -> e , t , ndis );
     }
}

void work ()
{
     int i;
     dfs1 ( 1 , 0 );
     dfs2 ( 1 , 0 , -999999 );
     //for ( i = 1 ; i <= N ; i++ )
     //{
     //    cout << m[i] << " " << endl;
     //}
     cout << ans << endl;
}

int main(int argc, char *argv[])
{
    init ();
    work ();
    //system("PAUSE");
    return EXIT_SUCCESS;
}