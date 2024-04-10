#include <iostream>
using namespace std;

int gcd(int a, int b){
    int t;
    while (b){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(){
    int p, q=0;
    cin >> p;
    for (int i=1; i<p; i++) if (gcd(i, p-1) == 1) q++;
    cout << q;
}