#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

        int n;cin >> n;
        long long ans = 1;
        for(int i=1;i<=n-1;++i) {
            ans*=i;
        }
        ans/=n/2;
        cout << ans << endl;
        
}