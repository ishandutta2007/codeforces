#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int a, b, c;

    cin >> a >> b >> c;


    cout << min( min( 2*a + 2*c, 2*b + 2*c ),  a + b + min( a + b, c ) );

    return 0;
}