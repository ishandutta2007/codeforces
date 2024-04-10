#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long a,b,t,sol;

int main(){
    cin >> a;
    cin >> b;
    while (a>0){
        if (a>=b){
            //serijska
            sol += a/b;
            a %= b;
        } else {
            //paralelna
            t = (b-1)/a;
            sol += t;
            b -= t*a;
        }
    }
    cout << sol;
    return 0;
}