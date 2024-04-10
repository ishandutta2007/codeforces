#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int s = a+b+c+d;
    if (2*(a+b) == s || 2*(a+c) == s || 2*(a+d) == s
        || 2*a == s || 2*b == s || 2*c == s || 2*d == s) cout << "YES";
    else cout << "NO";
    return 0;
}