#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,c0=0,c1=0;
    string a;
    cin >> n >> a;
    for (char c:a){
        c1 += (c == 'n');
        c0 += (c == 'z');
    }
    while (c1 > 0) {cout << 1 << ' '; c1 --;}
    while (c0 > 0) {cout << 0 << ' '; c0 --;}
}