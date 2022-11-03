#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int h[1000], a[1000];
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    if(k > (n+1)/2){
        k -= (n+1)/2;
        k = 2 * k;
    }else{
        k = 2 * k - 1;
    }
    cout << k;
    return 0;
}