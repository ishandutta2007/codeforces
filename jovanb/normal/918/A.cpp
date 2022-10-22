#include <bits/stdc++.h>
using namespace std;

bool fib[5000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n, y=1, z=1, x=1;
    cin >> n;
    fib[1] = 1;
    while(x <= 1000){
        x = y+z;
        fib[x] = true;
        z = y;
        y = x;
    }
    for(int i=1; i<=n; i++)cout << (fib[i] ? "O" : "o");
    return 0;
}