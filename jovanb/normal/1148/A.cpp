#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll a, b, c;
    cin >> a >> b >> c;
    ll res = 2*c;
    res += 2*min(a, b);
    if(a != b) res++;
    cout << res;
    return 0;
}