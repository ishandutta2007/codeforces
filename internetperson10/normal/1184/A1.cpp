#include <bits/stdc++.h>

using namespace std;
int main() {
    long long int n;
    cin >> n;
    if(n<=3 || n%2==0) cout << "NO\n";
    else cout << 1 << ' ' << (n-3)/2 << '\n';
}