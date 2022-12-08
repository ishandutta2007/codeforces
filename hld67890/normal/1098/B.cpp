#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int maxn = 310000;
int n , m;
char ch[6] = "AGCT";
char z[maxn] , t[maxn];
char anss[maxn];
int ans;
int get ( int x , int y ) {
    return x * m + y;
}
void work () {
    int i , j , k , l , o , p , t1 , t2 , sum;
    scanf ( "%d%d" , &n , &m );
    for ( i = 0 ; i < n ; i++ ) {
        scanf ( "%s" , z + i*m );
    }
    ans = 3000010;
    for ( i = 0 ; i < 4 ; i++ ) {
        for ( j = i + 1 ; j < 4 ; j++ ) {
            sum = 0;
            for ( l = 0 ; l < 4 ; l++ ) if ( l != i && l != j ) break;
            o = 0 + 1 + 2 + 3 - i - j - l;
            for ( k = 0 ; k < n ; k++ ) {
                t1 = t2 = 0;
                for ( p = 0 ; p < m ; p++ ) {
                    if ( k % 2 == 0 ) {
                        if ( p % 2 == 0 && z[get(k,p)] == ch[i] ) t1++;
                        if ( p % 2 == 1 && z[get(k,p)] == ch[j] ) t1++;
                        if ( p % 2 == 0 && z[get(k,p)] == ch[j] ) t2++;
                        if ( p % 2 == 1 && z[get(k,p)] == ch[i] ) t2++;
                    }
                    else {
                        if ( p % 2 == 0 && z[get(k,p)] == ch[l] ) t1++;
                        if ( p % 2 == 1 && z[get(k,p)] == ch[o] ) t1++;
                        if ( p % 2 == 0 && z[get(k,p)] == ch[o] ) t2++;
                        if ( p % 2 == 1 && z[get(k,p)] == ch[l] ) t2++;
                    }
                }
                if ( t1 > t2 ) {
                    for ( p = 0 ; p < m ; p++ ) {
                        if ( k % 2 == 0 ) {
                            if ( p % 2 == 0 ) t[get(k,p)] = ch[i];
                            else t[get(k,p)] = ch[j];
                        }
                        else {
                            if ( p % 2 == 0 ) t[get(k,p)] = ch[l];
                            else t[get(k,p)] = ch[o];
                        }
                    }
                }
                else {
                    for ( p = 0 ; p < m ; p++ ) {
                        if ( k % 2 == 0 ) {
                            if ( p % 2 == 0 ) t[get(k,p)] = ch[j];
                            else t[get(k,p)] = ch[i];
                        }
                        else {
                            if ( p % 2 == 0 ) t[get(k,p)] = ch[o];
                            else t[get(k,p)] = ch[l];
                        }
                    }
                }
            }
            sum = 0;
            for ( k = 0 ; k < n ; k++ ) for ( p = 0 ; p < m ; p++ ) if ( z[get(k,p)] != t[get(k,p)] ) sum++;
            if ( sum < ans ) {
                ans = sum;
                for ( k = 0 ; k < n ; k++ ) for ( p = 0 ; p < m ; p++ ) anss[get(k,p)] = t[get(k,p)];
            }
        }
    }

    for ( i = 0 ; i < 4 ; i++ ) {
        for ( j = i + 1 ; j < 4 ; j++ ) {
            sum = 0;
            for ( l = 0 ; l < 4 ; l++ ) if ( l != i && l != j ) break;
            o = 0 + 1 + 2 + 3 - i - j - l;
            for ( p = 0 ; p < m ; p++ ) {
                t1 = t2 = 0;
                for ( k = 0 ; k < n ; k++ ) {
                    if ( p % 2 == 0 ) {
                        if ( k % 2 == 0 && z[get(k,p)] == ch[i] ) t1++;
                        if ( k % 2 == 1 && z[get(k,p)] == ch[j] ) t1++;
                        if ( k % 2 == 0 && z[get(k,p)] == ch[j] ) t2++;
                        if ( k % 2 == 1 && z[get(k,p)] == ch[i] ) t2++;
                    }
                    else {
                        if ( k % 2 == 0 && z[get(k,p)] == ch[l] ) t1++;
                        if ( k % 2 == 1 && z[get(k,p)] == ch[o] ) t1++;
                        if ( k % 2 == 0 && z[get(k,p)] == ch[o] ) t2++;
                        if ( k % 2 == 1 && z[get(k,p)] == ch[l] ) t2++;
                    }
                }
                if ( t1 > t2 ) {
                    for ( k = 0 ; k < n ; k++ ) {
                        if ( p % 2 == 0 ) {
                            if ( k % 2 == 0 ) t[get(k,p)] = ch[i];
                            else t[get(k,p)] = ch[j];
                        }
                        else {
                            if ( k % 2 == 0 ) t[get(k,p)] = ch[l];
                            else t[get(k,p)] = ch[o];
                        }
                    }
                }
                else {
                    for ( k = 0 ; k < n ; k++ ) {
                        if ( p % 2 == 0 ) {
                            if ( k % 2 == 0 ) t[get(k,p)] = ch[j];
                            else t[get(k,p)] = ch[i];
                        }
                        else {
                            if ( k % 2 == 0 ) t[get(k,p)] = ch[o];
                            else t[get(k,p)] = ch[l];
                        }
                    }
                }
            }
            sum = 0;
            for ( k = 0 ; k < n ; k++ ) for ( p = 0 ; p < m ; p++ ) if ( z[get(k,p)] != t[get(k,p)] ) sum++;
            if ( sum < ans ) {
                ans = sum;
                for ( k = 0 ; k < n ; k++ ) for ( p = 0 ; p < m ; p++ ) anss[get(k,p)] = t[get(k,p)];
            }
        }
    }
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = 0 ; j < m ; j++ ) {
            printf ( "%c" , anss[get(i,j)] );
        }
        printf ( "\n" );
    }
}
int main () {
    work ();
    return 0;
}