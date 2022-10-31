#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long a[1234] , x , n , z , s , ss;

int main(){
    cin >> n >> x;
    for ( int i = 1; i <= n; i++) {
    	cin >> a[i];
    	if (a[i] > 0) s += a[i]; else ss += a[i]; 
    }
    if ( abs ( s+ss) % x != 0 )  s = ( abs ( s+ss) / x ) + 1;
    	else 
    		s = ( abs ( s+ss) / x ) ;
    cout<<s;
    return 0;
}