#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    ll n;
    cin >> n;
    ll left = 0, right = 1000, mid;
    while(right - left > 1){
        mid = ((right + left) >> 1LL);
        if(mid * (mid + 1LL) * (mid + 2LL) > 6LL * n){
            right = mid;
        }else{
            left = mid;
        }
    }
    cout << left << endl;
    return 0;
}