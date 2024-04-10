#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int d = abs(x-y);
    int v1 = t1*d;
    int v2 = (abs(z-x)+d)*t2+3*t3;
    if(v1 < v2) cout << "NO";
    else cout << "YES";

    return 0;
}