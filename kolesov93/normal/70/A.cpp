#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
	cout << 1 << endl;
	return 0;
    }
    int mod = 1000003;
    
    int res = 1;
    while (--n) {
	res = (res*3) % mod;
    }
    cout << res << endl;
    
    return 0;
}