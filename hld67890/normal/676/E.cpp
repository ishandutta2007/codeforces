#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

long long n , k;
long long a[120000];
char z[120];
long long ans;
int main () {
	long long i , j , l , f , flag;
	cin >> n >> k;
	f = 0;
	for ( i = 1 ; i <= n + 1 ; i++ ) {
		cin >> z;
		if ( z[0] == '?' ) f++,a[i-1] = -100000;
		l = strlen ( z );
		flag = 1; j = 0;
		if ( z[0] == '-' ) flag = -1,j=1;
		if (z[0]!='?') for ( ; j < l ; j++ ) a[i-1] = a[i-1] * 10 + (z[j]-'0');
		a[i-1] = a[i-1] * flag;
	}
	if ( k != 0 ) {
      	   if ( f >= 1 ) {
    		if ( n % 2 == 1 ) {
    			cout << "Yes" << endl;
    		}
    		else cout << "No" << endl;
    	}
    	else {
    		ans = a[n];
    		f = 0;
    		for ( i = n - 1 ; i >= 0 ; i-- ) {
    			ans = (ans * k + a[i]);
    			if ( ans >= 1e14 || ans <= -1e14 ) f = 1;
    			//cout << ans << endl;
    		}
    		if ( ans == 0 && f == 0 ) 
    			cout << "Yes" << endl;
    		else cout << "No" << endl;
    	}
    }
    else {
         if ( a[0] == -100000 ) {
               if ( (n+1-f) % 2 == 1 )
                  cout << "Yes" << endl;
                else
                 cout << "No" << endl;
         }
            else {
                 if ( a[0] == 0 ) 
                    cout << "Yes" << endl;
                 else {
                    cout << "No" << endl;
                  }
          }	 
    }
	return 0;
}