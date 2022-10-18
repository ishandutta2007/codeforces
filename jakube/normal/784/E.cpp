#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //
    int E = a ^ b;
    int F = c | d;
    int G = b & c;
    int H = a ^ d;

    int X = E & F;
    int Y = G | H;

    cout << (X ^ Y) << endl;
}