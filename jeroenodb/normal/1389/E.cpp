#include <iostream>
#include <algorithm>



using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)


int main() {
    int t;
    cin >> t;
    while(t--) {
    	int m,d,w;
    	cin >> m >> d >> w;
    	int b = min(m,d);
    	if(b==1) {
    		cout << 0 << endl; continue;
    	}
    	w = w/__gcd(w,d-1);

    	long long wraps = (b/w)+1, bigger = b%w;
    	//D(wraps);D(bigger);
    	long long ans = wraps*(wraps-1)*bigger/2;
    	ans += (wraps-1)*(wraps-2)*(w-bigger)/2;
    	cout << ans << endl;



    }
}