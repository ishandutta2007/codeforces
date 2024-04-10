#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll k = 0;
    ll m;
    ll l;

    if(a <= b - c){
        cout << n / a;
    } else {
        if(n >= b){
            k = (n - c) / (b - c);
            cout << k + (n - k * (b - c)) / a;
        }else{
            cout << n / a;
        }
    }
    return 0;
}