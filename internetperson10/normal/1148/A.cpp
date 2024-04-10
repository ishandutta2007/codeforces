#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a, b, c;
    cin >> a >> b >> c;
    if(a==b) cout << 2*c+a+b;
    else cout << 2*c+2*(min(a, b))+1;
}