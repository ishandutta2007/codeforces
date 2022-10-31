#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(){
    int a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    int g = gcd(a, b);
    int ga = a / g, gb = b / g;
    int cnt = 0;
    while(ga % 2 == 0) { ga /= 2; cnt++; }
    while(ga % 3 == 0) { ga /= 3; cnt++; }
    while(ga % 5 == 0) { ga /= 5; cnt++; }
    while(gb % 2 == 0) { gb /= 2; cnt++; }
    while(gb % 3 == 0) { gb /= 3; cnt++; }
    while(gb % 5 == 0) { gb /= 5; cnt++; }
    if(ga != 1 || gb != 1)
        cout << "-1" << endl;
    else
        cout << cnt << endl;
    return 0;
}