#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout << fixed;

    long long a, b, x;
    cin >> a >> b >> x;
    a = abs(a);
    b = abs(b);
    if(x < a+b)cout << "NO";
    else if((x-a-b)%2 == 0) cout << "YES";
    else cout << "NO";
    return 0;
}