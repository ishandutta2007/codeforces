#include <iostream>
using namespace std;

typedef long long llint;

llint a, b, c;
llint sol;

void srt() {
    if( b < c ) swap( b, c );
    if( a < b ) swap( a, b );
    if( b < c ) swap( b, c );
}

void smanji() {
    int x = c - c/2;
    a -= 2*x;
    c -= x;
    sol += x;
}

int main() {

    cin >> a >> b >> c;
    srt();

    while( c ) {
        if( c == a )
            sol += c, b = c = 0;
        smanji();
        srt();
    }

    if( b ) {
        if( b*2 >= a )
            sol += ( a + b ) / 3;
        else
            sol += b;
    }

    cout << sol;
    return 0;
}