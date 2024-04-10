#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

long long  n , k , m , t , z = 1, zz = 1 , ans , s;
long long a[1234567];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
        }
        sort (a , a+n);
        s = ans;
        ans += ans;
        for (int i = 0 ; i < n-2; i++) {
                s -= a[i];
        	ans +=s;
        		
        }
        if (n == 1)cout << ans / 2; else cout << ans;
	
	return 0;
}