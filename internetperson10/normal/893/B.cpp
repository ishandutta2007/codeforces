#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d=1, ans, c=2;
    cin >> n;
    while(n>=d) {
        if(n%d==0) ans = d;
        d*=4;
        d+=c;
        c*=2;
    }
    cout << ans;
}