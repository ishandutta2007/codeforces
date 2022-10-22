#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
int main() {
    ll t, x=0;
    cin >> t;
    for (int i=0; i<t; i++) {
        ll a,b,k, s=0;
        cin >> a >> b >> k;
        s += (k/2)*(a-b);
        s += (k%2)*a;
        cout << s << endl;
    }
}