#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int y, b, r;
    cin >> y >> b >> r;
    int x = min(y, min(b, r));
    while(b < x+1) x--;
    while(r < x+2) x--;
    cout << 3*x+3;
    return 0;
}