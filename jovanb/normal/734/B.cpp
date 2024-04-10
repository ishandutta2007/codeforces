#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll sum = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while(a && c && d){
        sum += 256;
        a--;
        c--;
        d--;
    }
    while(a && b){
        sum += 32;
        a--;
        b--;
    }
    cout << sum;
    return 0;
}