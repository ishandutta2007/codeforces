#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n; 
        cin >> n;
        if(n % 2050 != 0) {
            cout << "-1" << endl;
            continue;
        }
        n /= 2050;
        int cnt = 0;
        while(n > 0) {
            cnt += n % 10;
            n /= 10;
        }
        cout << cnt << endl;
    }
    return 0;
}