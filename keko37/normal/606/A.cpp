#include<iostream>

using namespace std;

int a, b, c, x, y, z, n, m, k;

int main () {
    cin >> a >> b >> c >> x >> y >> z;
    if (a>x) n=(a-x)/2; else n=a-x;
    if (b>y) m=(b-y)/2; else m=b-y;
    if (c>z) k=(c-z)/2; else k=c-z;
    if (n+m+k>=0) cout << "Yes"; else cout << "No";
    return 0;
}