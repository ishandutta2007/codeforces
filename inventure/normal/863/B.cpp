#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

const int maxn = 50 + 15;

int n , a[maxn << 1] , b[maxn << 1];

int main( int argc , char * argv[] ){
    cin >> n;
    n <<= 1;
    for(int i = 0 ; i < n ; ++ i) cin >> a[i];
    sort( a , a + n );
    int ret = 1 << 30;
    for(int i = 0 ; i < n ; ++ i)
        for(int j = i + 1 ; j < n ; ++ j){
            int len = 0;
            for(int k = 0 ; k < n ; ++ k)
                if( k != i && k != j )
                    b[len ++] = a[k];
            int w = 0;
            for(int k = 0 ; k < len ; k += 2)
                w += b[k + 1] - b[k];
            ret = min( ret , w );
        }
    cout << ret << endl;

    return 0;
}