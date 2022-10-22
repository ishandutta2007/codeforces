#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll a, b;
    cin >> a >> b;
    ll res = b/a;
    if(b%a) res++;
    cout << res;
    return 0;
}