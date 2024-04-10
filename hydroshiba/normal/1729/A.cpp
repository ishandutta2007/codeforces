#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long a, b, c;
    cin >> a >> b >> c;

    if(abs(a - 1) < abs(b - c) + abs(c - 1)) cout << 1;
    else if(abs(a - 1) > abs(b - c) + abs(c - 1)) cout << 2;
    else cout << 3;

    cout << '\n';
}

int main()
{
    int t;
    cin >> t;

    while(t--) solve();
}